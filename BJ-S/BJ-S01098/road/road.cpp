#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define inf (1000000007ll)
using namespace std;
int n,m,k;
int fa[11005];
void init(){for(int i=1;i<=n+k;i++)fa[i]=i;}
int rt(int x){return fa[x]==x?x:fa[x]=rt(fa[x]);}
int merge(int x,int y){
    //cout<<"merge "<<x<<","<<y<<"\n";
    int fax=rt(x),fay=rt(y);
    if(fax!=fay){
        fa[fax]=fay;
        return 1;
    }
    return 0;
}
struct edge{int u,v;ll w;}e[1000005],a[12][10005];
bool operator<(edge p,edge q){return p.w<q.w;}
int cnt,pos[12],len[12];
ll ans,c[12];
vector<edge>g;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);
    init();cnt=n-1;
    for(int i=1;i<=m&&cnt;i++){
        int u=e[i].u,v=e[i].v;
        ll w=e[i].w;
        if(merge(u,v)){
            ans+=w,cnt--;
            a[0][n-cnt-1].u=e[i].u;
            a[0][n-cnt-1].v=e[i].v;
            a[0][n-cnt-1].w=e[i].w;
        }
    }
    //cout<<ans;
    len[0]=n-1;//1~n-1
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            ll w;cin>>w;
            //添加的第i号点的边们
            a[i][j].u=j;
            a[i][j].v=i+n;
            a[i][j].w=w;
        }
        len[i]=n;//1~n
        sort(a[i]+1,a[i]+n+1);
    }
    for(int i=0;i<(1<<k);i++){
        vector<int>e;e.pb(0);//要用到哪些边
        ll res=0;
        for(int j=1;j<=k;j++)if(i&(1<<j-1))e.pb(j),res+=c[j];
        g.clear();memset(pos,0,sizeof pos);//该选第几条边
        init();cnt=n+e.size()-2;
        //for(auto j:e)cout<<j<<" len="<<len[j]<<" pos="<<pos[j]<<"\n";
        //cout<<"cnt="<<cnt<<"\n";
        while(cnt){
            int u,v;
            ll w=inf;
            for(auto j:e)
                if(pos[j]<len[j])w=min(w,a[j][pos[j]+1].w);
            for(auto j:e)
                if(pos[j]<len[j]&&w==a[j][pos[j]+1].w){
                    u=a[j][pos[j]+1].u,v=a[j][pos[j]+1].v;
                    //cout<<u<<"<->"<<v<<" w="<<w<<"\n";
                    pos[j]++;
                    break;
                }
            if(merge(u,v))res+=w,cnt--;//,cout<<"suc\n";

        }
        //cout<<i<<":"<<res<<"\n";
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
