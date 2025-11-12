#include <bits/stdc++.h>//48
using namespace std;
int n,m,k,x,y,z;
long long c[10005];
struct S{
    int x,y,p;
    long long l;
}s[2000005];
bool cmp(S x,S y){
    return x.l<y.l;
}
long long ans[3005];
int cc[2005],fa[2005][10005],o[2005],si[2005][10005];
int find(int k,int x){
    if(fa[k][x]!=x) return fa[k][x]=find(k,fa[k][x]);
    return x;
}
long long C(int x){
    long long rt=0;
    for(int i=1;i<=k;i++){if(x%2) rt+=c[i];x/=2;}
    return rt;
}

int cnt(int x){
    int rt=0;
    while(x){rt+=x%2; x/=2;}
    return rt;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int j=0;j<(1<<k);j++) {for(int i=1;i<=n+k;i++) fa[j][i]=i; o[j]=cnt(j)+n-1;}
    for(int i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),s[i].x=x,s[i].y=y,s[i].l=z;
    bool f=1;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        if(c[i]) f=0;
        for(int j=1;j<=n;j++) {scanf("%d",&z); s[++m].x=n+i,s[m].y=j,s[m].l=z,s[m].p=i;}
    }
    sort(s+1,s+m+1,cmp);
    if(f){
        for(int i=1;i<=m;i++){
            int fx=find(0,s[i].x),fy=find(0,s[i].y);
            if(fx!=fy&&cc[0]<n+k-1)ans[0]+=s[i].l,cc[0]++,fa[0][fx]=fy;
        }
        printf("%lld",ans[0]); return 0;
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<(1<<k);j++){
            int fx=find(j,s[i].x),fy=find(j,s[i].y);
            if(fx!=fy&&cc[j]<o[j]) if(!s[i].p||(j&(1<<s[i].p-1))) {ans[j]+=s[i].l,cc[j]++; if(si[j][fx]<si[j][fy])fa[j][fx]=fy,si[j][fy]+=si[j][fx]; else fa[j][fy]=fx,si[j][fx]+=si[j][fy];}
        }
    long long A=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<(1<<k);i++) A=min(A,ans[i]+C(i));
    printf("%lld",A);
    return 0;
}
