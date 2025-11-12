#include <bits/stdc++.h>
using namespace std;
int n,sa,sb,sc,ans,sum;
struct z{int a,b,c;}a[100010];
void dfs(int x,int ta,int tb,int tc) {
	if(x==n) {ans=max(ans,sum);return;}
	if(ta<n/2) sum+=a[x+1].a,dfs(x+1,ta+1,tb,tc),sum-=a[x+1].a;
	if(tb<n/2) sum+=a[x+1].b,dfs(x+1,ta,tb+1,tc),sum-=a[x+1].b;
	if(tc<n/2) sum+=a[x+1].c,dfs(x+1,ta,tb,tc+1),sum-=a[x+1].c;
}
void work() {
	ans=sum=0;sa=0,sb=0,sc=0;
	memset(a,0,sizeof a);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c,sa+=a[i].a,sb+=a[i].b,sc+=a[i].c;
	if(sc==0) {
		sort(a+1,a+n+1,[](z a,z b){return a.a-a.b>b.a-b.b;});
		for(int i=1;i<=n/2;i++) ans+=a[i].a;
		for(int i=1;i<=n/2+1;i++) ans+=a[i].b;
		cout<<ans<<"\n";return;
	}dfs(0,0,0,0);cout<<ans<<"\n";
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--) work();
}
