#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans=0;
int a[500005];
set<int> vis;
//bool vis[(1<<20)];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],ans+=(a[i]==k);
	int l=1,all=0;
	for(int r=1;r<=n;r++)
	{
		if(a[r]==k){all=0;l=r+1;vis.clear();continue;}//memset(vis,0,sizeof vis);
		all^=a[r];
		if(vis.count(all^k) || all==k)//vis[all^k]==1
		{
			ans++;l=r+1;all=0;
			vis.clear();
//			memset(vis,0,sizeof vis);
		}
		vis.insert(all);
//		vis[all]=1;
//		cout<<l<<" "<<r<<"\n";
//		cout<<all<<"\n";
	}
	cout<<ans;
	return 0;
}
