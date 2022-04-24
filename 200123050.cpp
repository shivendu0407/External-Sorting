#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define ppi pair<int,pair<int,int>>
using namespace std;
void mergeSubfiles(vector<vector<int>> subfiles,vector<vector<int>> &temp)
{
	vector<int> t;
	/*for(int i=0;i<subfiles.size();++i)
		for(int j=0;j<subfiles[i].size();++j)
			t.push_back(subfiles[i][j]);
	sort(t.begin(),t.end());	
	temp.push_back(t);*/
   priority_queue<ppi, vector<ppi>, greater<ppi>> qu;
   for (int i = 0; i<subfiles.size(); i++)
   		qu.push({ subfiles[i][0], { i, 0 } });
   while (!qu.empty()) 
   {
      ppi current_element = qu.top();
      qu.pop();
      int i = current_element.second.first;
      int j = current_element.second.second;
      t.push_back(current_element.first);
      if (j+1<subfiles[i].size())
      	qu.push({subfiles[i][j + 1],{ i, j + 1 }});
   }
   temp.push_back(t);
}
using namespace std;
int B;
int n;
int main()
{
	cin>>B>>n;
	int N;
	cin>>N;
	vector<vector<int>> files;
	int m = 0;
	while(m<N)
	{
		int i = 0;
		int j = 0;
		vector<int> curr;
		while(m<N&&j<B)
		{
		while(m<N&&i<n)
		{
			int t;
			cin>>t;
			curr.push_back(t);
			++i;
			++m;
		}
		++j;
		}
		sort(curr.begin(),curr.end());
		files.push_back(curr);
	}
	while(files.size()!=1)
	{
		vector<vector<int>> temp;
		int i = 0;
		while(i<files.size())
		{
			int j = 0;
			vector<vector<int>> subfiles;
			while(i<files.size()&&j<(B-1))
			{
				subfiles.push_back(files[i]);
				i++;
				j++;
			}
			mergeSubfiles(subfiles,temp);
		}
		files = temp;
	}
	for(int i=0;i<files.size();++i)
		for(int j=0;j<files[i].size();++j)
			cout<<files[i][j]<<endl;	
	return 0;
}