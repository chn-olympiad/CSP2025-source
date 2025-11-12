#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN=2e4+5,MAXM=1e6+5;
template<typename T>inline void read(T &x){
    bool f=1;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=!f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=(f?x:-x);return ;
}
template<typename T>inline void write(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');return ;
}
int n,m,k;
struct node{
    int u,v;
    LL w;
    bool operator <(const node &t)const{
        return w<t.w;
    }
    bool operator >(const node &t)const{
        return w>t.w;
    }
}e[MAXM];
LL c[15],a[15][MAXN];
int fa[MAXN],siz[MAXN];
inline int find(int x){
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}
LL ans;
node chs[MAXM],now[15][MAXM];
int chslen,nowlen[15];
vector<int>noww;
bool is[15];
void solve(){
    LL nans=0;
    int num=n;
    for(int i=1;i<=k;i++){
        if(is[i]){
            num++;nans+=c[i];
            if(nans>=ans)return ;
        }
        fa[n+i]=n+i;siz[n+i]=1;
    }
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    int len=chslen;
    int nnow[15]={0};
    for(int i=0;i<len;){
        LL minn=chs[i].w,minx=0;
        LL fx=find(chs[i].u),fy=find(chs[i].v);
        if(fx==fy){
            i++;
            continue;
        }
        for(int j=1;j<=k;j++){
            if(!is[j])continue;
            if(nnow[j]<nowlen[j]&&now[j][nnow[j]].w>chs[chslen-1].w)continue;
            while(nnow[j]<nowlen[j]){
                LL fx=find(now[j][nnow[j]].u),fy=find(now[j][nnow[j]].v);
                if(fx!=fy)break;
                else nnow[j]++;
            }
            if(nnow[j]<nowlen[j]&&minn>now[j][nnow[j]].w){
                minn=now[j][nnow[j]].w;
                minx=j;
            }
        }
        if(minx==0){
            fx=find(chs[i].u),fy=find(chs[i].v);
            nans+=chs[i].w;
            fa[fx]=fy;
            siz[fy]+=siz[fx];
            if(siz[fy]==num)break;
            i++;
        }else{
            fx=find(now[minx][nnow[minx]].u),fy=find(now[minx][nnow[minx]].v);
            nans+=now[minx][nnow[minx]].w;
            fa[fx]=fy;
            siz[fy]+=siz[fx];
            if(siz[fy]==num)break;
        }
    }
    ans=min(ans,nans);
}
bool vis[MAXN];
int main(){
    // LL tim=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n);read(m);read(k);
    for(int i=1;i<=m;i++){
        read(e[i].u);read(e[i].v);read(e[i].w);
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        for(int j=1;j<=n;j++){
            read(a[i][j]);
            now[i][nowlen[i]++]={n+i,j,a[i][j]};
        }
        sort(now[i],now[i]+nowlen[i]);
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx==fy)continue;
        fa[fx]=fy;
        siz[fy]+=siz[fx];
        ans+=e[i].w;
        chs[chslen++]=e[i];
        if(siz[fy]==n)break;
    }
    if(n>1000&&m>100000&&k>=9){
        for(int i=(1<<k)-1;i<(1<<k);i++){
            vis[i]=true;
            for(int j=1;j<=k;j++){
                if(i&(1<<(j-1))){
                    is[j]=true;
                }else{
                    is[j]=false;
                }
            }
            solve();
        }
        for(int ii=1;ii<=k;ii++){
            LL i=(1<<(ii-1));vis[i]=true;
            for(int j=1;j<=k;j++){
                if(i&(1<<(j-1))){
                    is[j]=true;
                }else{
                    is[j]=false;
                }
            }
            solve();
        }
        LL cntt=0;
        srand(time(0));
        while(cntt<=250){
            LL i=rand()%(1<<k);
            while(vis[i])i=rand()%(1<<k);
            for(int j=1;j<=k;j++){
                if(i&(1<<(j-1))){
                    is[j]=true;
                }else{
                    is[j]=false;
                }
            }
            solve();
            cntt++;
        }
    }else{
        for(int i=(1<<k)-1;i>=1;i--){
            for(int j=1;j<=k;j++){
                if(i&(1<<(j-1))){
                    is[j]=true;
                }else{
                    is[j]=false;
                }
            }
            solve();
        }
    }
    write(ans);
    // cerr<<clock()-tim<<endl;
}