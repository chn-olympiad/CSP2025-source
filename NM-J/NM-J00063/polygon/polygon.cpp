#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,k;
int a[N],vis[N],ma,ans,cnt,f;
void judge(int u)
{
	if(u>=3)
	{
//		cout<<u<<endl;
		ma=0;
		cnt=0;
//		cout<<"what i chose:";
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
//				cout<<a[i]<<" ";
				ma=max(a[i],ma);
				cnt+=a[i];
			}
		}
//		cout<<endl;
		if(cnt>ma*2)
		{
//			cout<<"why i chose:???";
//			cout<<cnt<<" "<<ma*2<<endl;
			ans++;
		}
	}
	return;
}
void dfs(int u,int w)
{
	for(int i=w+1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			judge(u+1);
			dfs(u+1,i);
			vis[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(0,0);
	cout<<ans%998244353;
	return 0;
}
/*
001
000
001
011
010
*/
