#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10005,M=1000005,inf=1e18;
int n,m,k,K;
int B[20005],tot1,tot2;
int w1[N],cst[12][N]; ll ans=inf,sum;
int find(int x){if(B[x]==x) return x; return B[x]=find(B[x]);}
void merge(int x,int y){B[find(x)]=find(y);}
struct edge{int p1,p2,w;}b[M],b2[N],b3[M];
inline bool cmp(edge x,edge y){return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

//	freopen("road1.in","r",stdin);
//	freopen("road5.out","w",stdout);

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>b[i].p1>>b[i].p2>>b[i].w;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++) B[i]=i;
	for(int i=1,x,y;i<=m;i++){
		x=find(b[i].p1),y=find(b[i].p2);
		if(x!=y) merge(x,y),b2[++tot1]=b[i];}
	m=tot1; for(int i=1;i<=m;i++) b[i]=b2[i];
//	assert(m==n-1);
	
	for(int i=1;i<=m;i++) b3[++tot2]=b[i];
	
	for(int i=0;i<k;i++){
		cin>>w1[i];
		for(int j=1;j<=n;j++){
			cin>>cst[i][j];
			b3[++tot2]=edge{n+1+i,j,cst[i][j]};
		}}
	sort(b3+1,b3+tot2+1,cmp);
	
	K=(1<<k);
	for(int b=0,x,y;b<K;b++){
		sum=0;
		for(int i=0;i<k;i++) if((b>>i)&1) sum+=w1[i];
		for(int i=1;i<=n+k;i++) B[i]=i;
		for(int i=1;i<=tot2;i++){
			if(b3[i].p1>=n+1) if(!((b>>(b3[i].p1-n-1))&1)) continue;
			x=find(b3[i].p1),y=find(b3[i].p2);
			if(x!=y){
				merge(x,y);
				sum+=b3[i].w;}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	fflush(stdout);
	return 0;}







