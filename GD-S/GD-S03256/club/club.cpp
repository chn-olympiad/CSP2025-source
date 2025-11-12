#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],ans,cnt[3],p[N];
struct node{int x,id,idn,v;};
bool operator<(node x,node y){return x.v>y.v;}
priority_queue<node>q[3];
void sol(int i,int d){
	ans+=a[i][d]; p[i]=d; ++cnt[d];
//	printf("%d %d %d\n",i,d+1,cnt[d]);
	for(int j=0;j<3;++j)
		if(j!=d) q[d].push((node){i,d,j,a[i][d]-a[i][j]});
	if(cnt[d]>n/2){
		while(q[d].top().id!=p[q[d].top().x]) q[d].pop();
		node t=q[d].top(); q[d].pop();
//		printf(":::%d %d->%d\n",t.x,t.id+1,t.idn+1);
		ans-=t.v; --cnt[t.id];
		p[t.x]=t.idn; ++cnt[t.idn];
		for(int j=0;j<3;++j)
			if(j!=t.idn) q[t.idn].push((node){t.x,t.idn,j,a[t.x][t.idn]-a[t.x][j]});
	}
}
void clr(){
	memset(p,0,sizeof(p));
	for(int i=0;i<3;++i)
		while(!q[i].empty()) q[i].pop();
	cnt[0]=cnt[1]=cnt[2]=ans=0;
}
void solve(){
	clr(); scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	for(int i=1;i<=n;++i){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) sol(i,0);
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) sol(i,1);
		else sol(i,2);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T); while(T--) solve();
	return 0;
}
