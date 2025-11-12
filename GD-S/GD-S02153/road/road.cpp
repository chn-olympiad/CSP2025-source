//注意到 m 条边中只需要保留最小生成树的 n-1 条便即可！
//待会再来卡常
#include<bits/stdc++.h>
#define ll long long
#define IL inline
#define bit(S,i) (((S)>>(i))&1)
using namespace std;
const int N=10010,M=1000010,K=15;
const ll inf=1e18;
struct node{
	int x,y,w;
}p[M],a[K][N],q[M+N*K];
int n,m,k,t,c[K],fa[N+K];
basic_string<node> v[1<<15];
ll ans=inf;
IL void rd(int &s){
	s=0;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
IL int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
IL void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return ;
	fa[y]=x;
}
IL void radix_sort(node *q,int n){
	int cnt=0;
	for(int i=0;i<(1<<15);i++) v[i].clear();
	for(int i=1;i<=n;i++) v[q[i].w&((1<<15)-1)].push_back(q[i]);
	cnt=0;
	for(int i=0;i<(1<<15);i++){
		for(auto j:v[i]) q[++cnt]=j;
	}
	for(int i=0;i<(1<<15);i++) v[i].clear();
	for(int i=1;i<=n;i++) v[q[i].w>>15].push_back(q[i]);
	cnt=0;
	for(int i=0;i<(1<<15);i++){
		for(auto j:v[i]) q[++cnt]=j;
	}
}
int main(){
//	system("fc road.out road4.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%d%d%d",&n,&m,&k);
	rd(n),rd(m),rd(k);
	for(int i=1;i<=m;i++){
//		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
		rd(p[i].x),rd(p[i].y),rd(p[i].w);
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(p[i].x)==find(p[i].y)) continue;
		merge(p[i].x,p[i].y);
		p[++t]=p[i];
	}
	for(int i=1;i<=k;i++){
//		scanf("%d",&c[i]);
		rd(c[i]);
		for(int j=1;j<=n;j++){
//			scanf("%d",&a[i][j].w);
			rd(a[i][j].w);
			a[i][j].x=n+i,a[i][j].y=j;
		}
	}
	for(int S=0;S<(1<<k);S++){
		ll res=0;
		int mt=t;
		for(int i=1;i<=t;i++) q[i]=p[i];
		for(int i=1;i<=k;i++){
			if(bit(S,i-1)){
				res+=c[i];
				for(int j=1;j<=n;j++) q[++mt]=a[i][j];
			}
		}
//		sort(q+1,q+mt+1,cmp);
		radix_sort(q,mt);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=mt;i++){
			if(find(q[i].x)==find(q[i].y)) continue;
			merge(q[i].x,q[i].y);
			res+=q[i].w;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
