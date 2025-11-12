#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],v[N];
int n,m,ans;
void dfs(int c,int bb)
{
	if(c>n)
	{
		if(n-bb>=m)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			if(a[c]==0||bb>=b[i])
			bb++;
			v[i]=1;
			dfs(c+1,bb);
			v[i]=0;
			if(a[c]==0||bb>=b[i])
			bb--;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int vp=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
		if(a[i]==1)
		vp++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(vp==n)
	{
		int s=1;
		for(int i=n;i>=1;i--)
		{
			s*=i;
			s%=998244353;
		}
		cout<<s<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
//原神（袁神）启动！ 
