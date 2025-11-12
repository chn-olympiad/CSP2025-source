#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],st[N];
int n,m;
long long ret=0;
vector<int>v;
void print()
{
	if(v.size()>=m)
	{	
		for(int i = 1 ; i<= v.size() ;i++)
		{
			ret+=i;
		}
//		for(auto x: v)
//		{
//			cout << x<<" ";
//		}
//		cout <<endl;
	}
	

}
void dfs(int u)
{
	if(u== n+1)
	{
		print();
		return ;
	}
	if(st[u]==0)
	{
		st[u]=1;
		v.push_back(u);
		dfs(u+1);
		v.pop_back();
		st[u]=0;
		
	}
	dfs(u+1);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	string s;
	cin >>s;
	for(int i = 0 ; i < n ; i++)
	{
		cin >>a[i];
	}
	dfs(1);
	cout << ret;
	return 0;
}
