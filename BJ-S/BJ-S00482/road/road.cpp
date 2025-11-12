#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define co(x) cerr<<#x<<":"<<x<<"\n"
#define dbg cerr<<"--------\n"
#define endl '\n'
#define fi first
#define sc second
#define ls x<<1
#define rs (x<<1)|1
const int inf=3e18;
const int mod=1e9+7;
const int N=2e4+5,M=1e6+5;
int n,m,q,k,x,y,z,T,L,V,len,ans,now,sum,cnt,h,flag;
int f[N],g[15][N],w[15],siz[N];
struct node{
    int x,y,z;
}a[M],b[N],c[M];
inline bool cmp(node x,node y){
    return x.z<y.z;
}
inline void cr(){
    for(int i=1;i<=n+10;i++) f[i]=i,siz[i]=1;
}
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
inline void merge(int x,int y){
    if(siz[find(x)]<siz[find(y)]){
        siz[find(y)]+=siz[find(x)];
        f[find(x)]=find(y);
    }else{
        siz[find(x)]+=siz[find(y)];
        f[find(y)]=find(x);
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    for(int i=1;i<=k;i++){
        cin>>w[i];
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    sort(a+1,a+1+m,cmp);
    cr();
    for(int i=1;i<=m;i++){
        if(find(a[i].x)!=find(a[i].y)){
            ans+=a[i].z;
            merge(a[i].x,a[i].y);
            b[++cnt]=a[i];
        }
        if(cnt==n-1) break;
    }
    for(int i=1;i<(1<<k);i++){
        now=sum=len=0;cr();
        h=n;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                sum+=w[j];h++;flag=1;
                for(int l=1;l<=n;l++){
                    if(g[j][l]>=b[cnt].z) continue;
                    c[++now]=(node){h,l,g[j][l]};
                    flag=0;
                }
                h-=flag;
            }
        }
        for(int j=1;j<=cnt;j++){
            c[++now]=b[j];
        }
        sort(c+1,c+1+now,cmp);
        for(int j=1;j<=now;j++){
            if(find(c[j].x)!=find(c[j].y)){
                sum+=c[j].z;
                merge(c[j].x,c[j].y);
                len++;
            }
            if(len==h-1) break;
        }
        if(len==h-1) ans=min(ans,sum);
    }
    cout<<ans<<endl;
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
