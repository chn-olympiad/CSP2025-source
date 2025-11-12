#include<bits/stdc++.h>
#define N (1<<21)
using namespace std;
int n,m,ans,a[N],b[N],nxt[N],suf[N],vis[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	memset(vis,63,sizeof(vis));
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]^a[i];
	for(int i=n;i>=1;i--) vis[b[i]]=i,nxt[i]=vis[b[i-1]^m];
	suf[n]=nxt[n];
	for(int i=n-1;i>=1;i--) suf[i]=min(suf[i+1],nxt[i]);
	for(int i=1;i<=n;)
	{
		if(suf[i]<=n) ans++;
		i=suf[i]+1;
	}
	cout<<ans;
	return 0;
}

