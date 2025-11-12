#include<bits/stdc++.h>
#define int long long
using namespace std;
const int oo=0x7FFFFFFFFFFFFll;
const int N=1e4+15;
const int M=1e6+15;
struct node{int u,v,w;}x[M];
int f[N],c[15],a[15][N],U[M],V[M],W[M],per[15],n,m,k;
bool cmp(node a1,node a2){return a1.w<a2.w;}
int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}
bool Add(int x1,int x2){
    int y1=Find(x1),y2=Find(x2);
    if(y1==y2)return true;
    f[y1]=y2;
    return false;
}
int Brute_force1(int n,int m){
    int cnt=0,ans=0;
    sort(x+1,x+1+m,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
//		printf("%lld %lld %lld\n",x[i].u,x[i].v,x[i].w);
//		printf("#5720#\n");
        if(Add(x[i].u,x[i].v))continue;
        ++cnt,ans+=x[i].w;
        if(cnt==n-1)break;
//        for(int j=1;j<=n;j++)printf("f[%lld]=%lld ",j,f[j]);
//        printf("\n");
    }
    return ans;
}
int C(int i,int r,int sz){
//    printf("%lld %lld %lld\n",i,r,sz);
//    for(int j=1;j<=sz;j++)printf("%lld ",per[j]);
//    printf("\n\n");
    if(sz==r){
        int cnt=m,now=0;
        for(int j=1;j<=m;j++)x[j]={U[j],V[j],W[j]};
        for(int j=1;j<=sz;j++){
            int p=per[j];
            now+=c[p];
            for(int q=1;q<=n;q++)x[++cnt]={j+n,q,a[p][q]};
        }
        return now+Brute_force1(n+sz,cnt);
    }
    if(i+r-sz>k)return oo;
    int ans=oo;
    for(int j=i+1;j<=k;j++){
        per[sz+1]=j;
        ans=min(ans,C(j,r,sz+1));
        per[sz+1]=0;
    }
    return ans;
}
int Brute_force3(int sz){
	int cnt=m,now=0;
	memset(x,0,sizeof(x));
	for(int j=1;j<=m;j++)x[j]={U[j],V[j],W[j]};
	for(int j=1;j<=sz;j++){
		int p=per[j];
		now+=c[p];
		for(int q=1;q<=n;q++)x[++cnt]={j+n,q,a[p][q]};
	}
	return now+Brute_force1(n+sz,cnt);
}
void Brute_force2(){
	int ans=oo;
    for(int i=0;i<=k;i++)ans=min(ans,C(0,i,0));
    printf("%lld\n",ans);
    return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++)scanf("%lld%lld%lld",&u,&v,&w),U[i]=u,V[i]=v,W[i]=w;
    for(int i=1;i<=k;i++){
        scanf("%lld",c+i);
        for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
    }
    if(k==0)printf("%lld\n",Brute_force1(n,m)),exit(0);
    else Brute_force2(),exit(0);
	return 0;
}
