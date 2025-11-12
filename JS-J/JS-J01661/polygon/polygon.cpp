#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005],f[5005];
long long ans=0;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int dep,int q,int cnt,int maxx,int last)
{
	if(dep>q)
	{
		if(cnt>maxx*2)
		{
			ans++;
//			cout<<cnt<<" "<<maxx<<" ";
//			for(int i=1;i<=n;i++)
//			{
//				if(f[i]) cout<<a[i]<<" ";
//			}
//			cout<<endl;
		}
		return ;
	}
	for(int i=last;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(dep+1,q,cnt+a[i],max(maxx,a[i]),i);
			f[i]=0;
		}
	}
}
long long F(int a,int b)
{
	long long x=1,y=1;
	for(int i=a+1;i<=b;i++)
	{
		x*=i;
	}
	for(int i=1;i<=b-a;i++)
	{
		y*=i;
	}
	return x/y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=max(a[i],t);
	}
	sort(a+1,a+n+1,cmp);
	if(t<=1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=F(i,n);
			ans%=mod;
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			dfs(1,i,0,0,1);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
