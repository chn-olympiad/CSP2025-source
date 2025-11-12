#include<bits/stdc++.h>
#define ll long long
#define N 5100
using namespace std;

const int mod=998244353;

ll n,ans=0;
ll a[N],vis[N],flag[N];

void dfs(ll l,ll num,ll maxx,ll last)// 长度 累加和 最大值 
{
	if(l>=3 && num>maxx*2)
	{
		ans++;
//		cout<<l<<" "<<num<<" "<<maxx<<"\n";
		ans%=mod;
	} 
	for(int i=last+1;i<=n;i++)
	{
		if(!vis[i] && !flag[i])
		{
			vis[i]=true;
			dfs(l+1,num+a[i],max(maxx,a[i]),i);
			vis[i]=false;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	memset(vis,false,sizeof(vis));
	memset(flag,false,sizeof(flag));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
//		memset(vis,false,sizeof(vis));
		flag[i]=true;
//		cout<<"#"<<i<<"#\n";
		dfs((ll)1,a[i],a[i],i);
	}
	cout<<ans;
	return 0;
}
