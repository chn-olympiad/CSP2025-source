#include<bits/stdc++.h>
using namespace std;
vector<int>v;
long long n;
const int N=1e4+10;
long long a[N],st[N]={0};
long long b[N];
long long ret=0;
void po()
{
	if(v.size()>=3)
	{
		
		long long mx=-100000,js=0,ad=0;
		for(auto x: v)
		{
//			cout <<a[x]<<" ";
			mx=max(a[x],mx);
			ad+=a[x];
		}
//		cout <<endl;
		if(ad>mx*2)ret++;
	}
	
	
}
void dfs(int u)
{
	if(u==n+1)
	{
		po();
		return ;
	}

	if(st[u]==0)
	{		
		v.push_back(u);
		st[u]=1;
		dfs(u+1);
		st[u]=0;
		v.pop_back();
		dfs(u+1);
	}
		
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1 ; i <= n ;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ret%998244353;
	return 0;
}
