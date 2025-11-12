#include<bits/stdc++.h>
using namespace std;
int a[5001];
int ans=0;
int n;
/*void dfs(int noo,int now,int s,int maxn)
{
	if (now==n)
	{
		cout<<"ok"<<noo<<maxn<<endl;
		if (s>maxn*2&&noo>=3)
		ans++;
		return;
	}
	dfs(noo+1,now+1,s+a[now],max(maxn,a[now]));
	dfs(noo,now+1,s,maxn);
}*/ 
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//dfs(0,1,0,0);
	for (int i=1;i<=n-3;i++)
	{
		for (int j=i+3;j<=n;j++)
		{
			int s=0,maxn=-1;
			for (int z=i;z<=j;z++)
			{
				s+=a[z];
				maxn=max(maxn,a[z]); 
			}
			if (s>maxn*2)
			{
				ans=(ans+1)%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
} 
