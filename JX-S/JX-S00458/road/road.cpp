#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF=0x7fffffffffffffff;
int n,m,k;long long ans=INF,a[15][10005],c[15];//LONG LONG IS VERY IMPORTANT!!!
int fa[10005];bool f[15];
int fd(int x){
    if(fa[x]==x) return x;
    fa[x]=fd(fa[x]);
    return fa[x];
}
struct edge{
    int u,v,id;
    long long w;
}e[1100005];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
bool pmc(edge x,edge y){
    return x.id<y.id;
}
void dfs(int dep,int num){
    if(dep>k){
        long long tmp=0;int nn=n,mm=m;
        for(int i=1;i<=k;i++){
            if(f[i]){
                tmp+=c[i];nn++;
                for(int j=1;j<=n;j++){
                    mm++;
                    e[mm].u=j;
                    e[mm].v=nn;
                    e[mm].w=a[i][j];
                    e[mm].id=mm;
                }
            }
        }
        for(int i=1;i<=nn;i++) fa[i]=i;
        sort(e+1,e+1+mm,cmp);
        for(int i=1;i<=mm;i++){
            int a=fd(e[i].u),b=fd(e[i].v);
            if(a!=b){
                tmp+=e[i].w;
                fa[a]=b;
            }
        }
        if(tmp<ans) ans=tmp;
        sort(e+1,e+1+mm,pmc);
        return ;
    }
    f[dep]=true;
    dfs(dep+1,num+1);
    f[dep]=false;
    dfs(dep+1,num);
}
void solve(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i;
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
    }
    dfs(1,0);
    printf("%lld",ans);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//Why is it a graph problem??? I have to use some magic algorithms...
//Designant.
//Antithese
//Fractured Ray
//Testify (However, I'm not an Arcaea player.)
//Bounded Quietude
//BANGING STRIKE (I'm not sure about this...)
//Spasmodic
//Igallta
//Rrhar'il
//Crave Wave
//The Chariot ~REVIILE~
//Luminescence
//Retribution
//DESTRUCTION 3,2,1 (That's my feeling now!)
//Distorted Fate (However, I'm not a Phigros player either.)
//Komplexe
//sølips (Guess why I can type that character 'ø' without copying.)
//QZKago Requiem
//PANDORA PARADOXXX (Of course, I'm not a maimai player...)
//Gold Town
//REANIMATE
//Quo Vadis
//Double Agent
//PLEASE (Nothing to say... I don't play music games...)
//CR200J CR220J CR300AF CR300BF CR400AF CR400BF CR450AF CR450BF (To tell the truth, I'm really a train lover!)
//So how can I solve this problem? nope:(              )
//But only 16 pts I can get... (NEED KRUSKAL?)
//UPDATE 17:30 Maybe 32 pts? I add 'k' into my program, but it was TLE on Example 2.
//So I can't get the 1st prize in CSP-S...
//And I should fight for the senior high school entrance examination, so...
//GOODBYE, OI.
//AFOed on November 1st, 2025.
