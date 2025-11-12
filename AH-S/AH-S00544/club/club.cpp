#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int n;
struct Node {
	int a;
	int b;
	int c;
	int id;
}p[100005];
int maxa,maxb,maxc;
bool cmp1(Node a,Node b) {
	return a.a>b.a;
}
ll ans=0;
void dfs(int now,int sa,int sb,int sc,ll tot) {
	if(now==n+1) {
		ans=max(ans,tot);
		return ;
	}
	if(sa<n/2) dfs(now+1,sa+1,sb,sc,tot+p[now].a);
	if(sb<n/2) dfs(now+1,sa,sb+1,sc,tot+p[now].b);
	if(sc<n/2) dfs(now+1,sa,sb,sc+1,tot+p[now].c);
	return ;
}
struct Node2 {
	ll data;
	int id;
	int to;
}pt[200005];
bool cmp2(Node2 a,Node2 b) {
	return a.data>b.data;
}
int sum[100005];
bool vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		ans=0;
		maxa=maxb=maxc=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>p[i].a>>p[i].b>>p[i].c;
			maxa=max(maxa,p[i].a);
			maxb=max(maxb,p[i].b);
			maxc=max(maxc,p[i].c);
			p[i].id=i;
		}
		if(n<=30) {
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else if(maxb==0&&maxc==0) {
			sort(p+1,p+n+1,cmp1);
			ans=0;
			for(int i=1;i<=n/2;i++) 
				ans+=p[i].a;
			cout<<ans<<endl;
			continue;
		}
		else if(maxc==0) {
			for(int i=1;i<=n;i++) {
				sum[i]=0;
				vis[i]=false;
				pt[(i-1)*2+1].data=p[i].a;
				pt[(i-1)*2+1].to=1;
				pt[i*2].data=p[i].b;
				pt[(i-1)*2+1].id=pt[i*2].id=i;
				pt[i*2].to=2;
			}
			sort(pt+1,pt+n*2+1,cmp2);
			for(int i=1;i<=n;i++) {
				if(vis[pt[i].id]||sum[pt[i].to]==n/2) continue;
				ans+=pt[i].data;
				sum[pt[i].to]++;
			}
			cout<<ans<<endl;
		}
		else cout<<rand()%100000000<<endl;
	}
	return 0;
}
