#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int id;
	ll x;
};
int T,n,a[N][4];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline int _max(node x,node y,node z){
	if(x.x>=y.x && x.x>=z.x) return x.id;
	if(y.x>=x.x && y.x>=z.x) return y.id;
	if(z.x>=y.x && z.x>=x.x) return z.id;
}
inline bool cmp1(node x,node y){
	int id1=x.id;
	int id2=y.id;
	return a[id1][1]-max(a[id1][2],a[id1][3])<a[id2][1]-max(a[id2][2],a[id2][3]);
}
inline bool cmp2(node x,node y){
	int id1=x.id;
	int id2=y.id;
	return a[id1][2]-max(a[id1][1],a[id1][3])<a[id2][2]-max(a[id2][1],a[id2][3]);
}
inline bool cmp3(node x,node y){
	int id1=x.id;
	int id2=y.id;
	return a[id1][3]-max(a[id1][2],a[id1][1])<a[id2][3]-max(a[id2][2],a[id2][1]);
}
inline void solve(){
	int t[N]={},cnt[4]={};
	ll ans=0;
	vector<node> g[4];
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++){
		int p=_max({1,a[i][1]},{2,a[i][2]},{3,a[i][3]});
		g[p].push_back({i,a[i][p]});
		ans+=a[i][p];
	}
	if(g[1].size()>n/2){
		int tmp=g[1].size()-n/2;
		sort(g[1].begin(),g[1].end(),cmp1);
		for(int i=0;i<tmp;i++){
			int id=g[1][i].id;
			ll v=g[1][i].x;
			ans-=v;
			ans+=max(a[id][2],a[id][3]);
		}
	}
	if(g[2].size()>n/2){
		int tmp=g[2].size()-n/2;
		sort(g[2].begin(),g[2].end(),cmp2);
		for(int i=0;i<tmp;i++){
			int id=g[2][i].id;
			ll v=g[2][i].x;
			ans-=v;
			ans+=max(a[id][1],a[id][3]);
		}
	}
	if(g[3].size()>n/2){
		int tmp=g[3].size()-n/2;
		sort(g[3].begin(),g[3].end(),cmp3);
		for(int i=0;i<tmp;i++){
			int id=g[3][i].id;
			ll v=g[3][i].x;
			ans-=v;
			ans+=max(a[id][2],a[id][1]);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}
