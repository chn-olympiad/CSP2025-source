#include <bits/stdc++.h>
using namespace std;
//freopen
#define int long long
int n,a[5010],b[5010],vis[5010],tot_a,tot,mx[5010],ans,jiangly=998244353;
void dfs(int x) {
	if(x>2&&tot>mx[x-1]*2) ans++,ans=ans%jiangly;
	if(x==n+1) return;
	for(int i=b[x-1];i<=n;i++)
		if(!vis[i]) b[x]=i,tot+=a[i],mx[x]=max(mx[x-1],a[i]),vis[i]=1,dfs(x+1),vis[i]=0,mx[x]=0,tot-=a[i];
}int calc(int x){int y=1;while(x--) y<<=1,y=y%jiangly;return y;}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;b[0]=a[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i],tot_a+=a[i];
	sort(a+1,a+n+1);
	if(tot_a==n) {cout<<calc(n)-n-1-n*(n-1)/2;return 0;}
	dfs(1);cout<<ans;
}
