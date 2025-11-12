#include<cstdio>
#include<cstdlib>
typedef long long LL;
int n,m,k;

const int N=10003, M=1e6+3, K=13;

LL MINL(LL x, LL y) {return x<y? x:y; }

struct edge {
	int u, v; LL w;
	edge(int __u=0, int __v=0, LL __w=0) {u=__u, v=__v, w=__w; }//构造函数 
} e[M], et[M], ett[M];
bool operator<=(edge e1, edge e2) {return e1.w<=e2.w; }

template<typename AU>
void sort(AU *alpha, AU *beta, int le, int ri) {
	if(le>=ri) return ;
	int mid=(le+ri)>>1;
	sort(alpha,beta,le,mid), sort(alpha,beta,mid+1,ri);
	int i=le, j=mid+1, k=le;
	while(i<=mid&&j<=ri) (alpha[i]<=alpha[j])? (beta[k++]=alpha[i++]) : (beta[k++]=alpha[j++]);
	while(i<=mid) {beta[k++]=alpha[i++]; } while(j<=ri) beta[k++]=alpha[j++];
	for(i=le;i<=ri;++i) alpha[i]=beta[i];
}

struct Union_Find_Set {
	int fa[N+K]={};
	void reset(int x) {for(int i=1;i<=x;++i) fa[i]=i; } 
	int find(int x) {return (fa[x]==x)? x:(fa[x]=find(fa[x])); }
	void Union(int x, int y) {fa[find(y)]=find(x); }
	bool sameset(int x, int y) {return find(x)==find(y); }
} ufs;

LL c[K], a[K][N+K];

LL kruskal(int zn, int zm) {
	for(int i=1;i<=zm;++i) et[i]=e[i];//万万不能将e[i]排序
	//因为否则加入的边会和原有的混淆 
	sort(et,ett,1,zm);
	ufs.reset(zn);
	LL ans=0;
	for(int i=1,alpha=0;i<=zm;++i) {
		int u=et[i].u, v=et[i].v;
		if(!ufs.sameset(u,v)) {
			ufs.Union(u,v), ans+=et[i].w, ++alpha;
			if(alpha==zn-1) return ans;
		}
	} return 0x1FFFffffFFFFffff;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%i%i%i",&n,&m,&k);
	for(int i=1;i<=m;++i) {
		int u=0,v=0; LL w=0;
		scanf("%i%i%lli",&u,&v,&w);
		e[i]=edge(u,v,w);
	}
	bool spA=false;
	for(int i=1;i<=k;++i) {//乡村 
		bool BO=true;
		scanf("%lli",&c[i]);  if(c[i]) BO=false;
		for(int j=1;j<=n;++j) {
			scanf("%lli",&a[i][j]);
			if(a[i]) BO=false;
		} spA=spA||BO; 
	}
	if(spA) {puts("0"); return 0; }//建个乡村，连接所有城市，费用为0 
	LL sigma=0x1FFFffffFFFFffff;
	for(int stt=0; stt<(1<<k); ++stt) {
		int leng=0, then=m+1, ve[K]={};//ve：被开放乡村的编号 
		for(int i=1; i<=k; ++i) {//注意下标是从1开始 
			if(stt&(1<<(i-1))) ve[leng++]=i;
		} 
		LL ans=0;
		for(int i=0; i<leng; ++i) {//开放的乡村编号 
			ans+=c[ve[i]];//开辟乡村代价 
			for(int j=1;j<=n;++j) e[then++]=edge(n+ve[i],j,a[ve[i]][j]);//新边
		}
		sigma=MINL(sigma,ans+kruskal(n+leng, then-1));
	} printf("%lli",sigma);
	return 0;
}
