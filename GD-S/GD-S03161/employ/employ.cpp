#include<bits/stdc++.h>
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define fans(x) freopen(#x".ans","w",stdout)
const int N=507;
using namespace std;
int n,m,c[N],b[N],num[N],vis[N],ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int res=0;
		for(int i = 1,sum=0;i<= n;i++)
		{
			if(c[num[i]]<=sum||b[i]==0)sum++;
			else res++;
		}
		ans+=(res>=m);
		return;
	}
	for(int i = 1;i<= n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		num[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main()
{
//	fin(employ);
//	fout(employ);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<= n;i++)
	{
		char c;cin>>c;
		b[i]=c-'0';
	}
	for(int i = 1;i<= n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
}

