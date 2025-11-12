#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
const int maxn=10100,maxm=2000000,maxk=13;
#define int long long
struct edge{
    int x,y,cst,flag;
    friend bool operator<(edge xx,edge yy){
        return (xx.flag^yy.flag)?xx.flag:bool(xx.cst<yy.cst);
    }
}v[maxm],w[maxk][maxn];int uu,cnt1,cnt2[maxk];
int n,m,k,xx,yy,zz,tttt,c[maxk],cnt,use[maxk];
int fa[maxn],siz[maxn],ans,answer;
int father(int kkk){
    if(fa[kkk]==kkk)return kkk;
    return fa[kkk]=father(fa[kkk]);
}
bool same(int xxx,int yyy){
    int f1=father(xxx),f2=father(yyy);
    return bool(f1==f2);
}
void merge(int xxx,int yyy,int cs){
    int f1=father(xxx),f2=father(yyy);
    if(siz[f1]>=siz[f2])fa[f2]=f1,siz[f1]+=siz[f2];
    else fa[f1]=f2;siz[f2]+=siz[f1];
    ans+=cs;
}
void kruscal(){
    for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
    cnt1=1;for(int i=1;i<=cnt;i++)cnt2[use[i]]=1;
    for(int i=1;i<n+cnt;i++){
        int minn=1e10,mp=100;
        while(cnt1<uu&&same(v[cnt1].x,v[cnt1].y))cnt1++;
        if(v[cnt1].cst<minn)mp=0,minn=v[cnt1].cst;
        for(int j=1;j<=cnt;j++){
            int tt=use[j];
            while(cnt2[tt]<=n&&same(w[tt][cnt2[tt]].x,w[tt][cnt2[tt]].y))cnt2[tt]++;
            if(w[tt][cnt2[tt]].cst<minn)mp=tt,minn=w[tt][cnt2[tt]].cst;
        }
        if(mp==0){
            merge(v[cnt1].x,v[cnt1].y,v[cnt1].cst);
            if(cnt==0)v[cnt1].flag=1;cnt1++;
        }
        else merge(w[mp][cnt2[mp]].x,w[mp][cnt2[mp]].y,w[mp][cnt2[mp]].cst),cnt2[mp]++;
    }
    answer=min(answer,ans);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //clock_t st=clock();
    answer=1e18;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>xx>>yy>>zz;
        v[i]={xx,yy,zz};
    }
    sort(v+1,v+m+1);uu=m+1;kruscal();sort(v+1,v+m+1);uu=n;//int zz=1;while(v[zz].flag)zz++;cout<<tttt<<" "<<zz<<"\n";
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>xx;w[i][j]={j,n+i,xx};
        }
        sort(w[i]+1,w[i]+n+1);
    }
    v[n].cst=1e10;for(int i=1;i<=k;i++)w[i][n+1].cst=1e10;
    for(int i=1;i<(1<<k);i++){
        ans=cnt=0;
        for(int j=1;j<=k;j++)if(i&1<<j-1)use[++cnt]=j,ans+=c[j];
        kruscal();
    }
    cout<<answer;
    //clock_t en=clock();
    //cerr<<"\n"<<(en-st)*1.0/CLOCKS_PER_SEC;
    return 0;
}