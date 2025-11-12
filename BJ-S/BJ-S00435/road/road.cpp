#include<bits/stdc++.h>
#define ll long long
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    int f=1;char c=getchar();x=0;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int M=1e6+10,N=1e4+10;
int n,m,k,c[11][N],val[N],ava[N];
vector<pair<int,pair<int,int> > > ed,e,se;
struct EDGE{
    int u,v,w;
}ED[2*M];
int edcnt;
bool cmp(EDGE a,EDGE b){return a.w<b.w;}
namespace DSU{
    int f[N];
    void init(){rep(i,1,n+k) f[i]=i;}
    int getfa(int x){return f[x]==x?x:f[x]=getfa(f[x]);}
    void merge(int x,int y){
        f[getfa(x)]=getfa(y);
    }
}
ll solve(int ccnt){
    ll res=0;
    //sort(se.begin(),se.end());
    DSU::init();
    int cnt=0;
    rep(i,0,(int)se.size()-1){
        int u=se[i].second.first,v=se[i].second.second,w=se[i].first;
        if(u>n&&!ava[u-n]) continue;
        //else if(u>n) cout<<"!"<<endl;
        int fu=DSU::getfa(u),fv=DSU::getfa(v);
        if(fu!=fv){
            //cout<<u<<" "<<v<<" "<<w<<endl;
            DSU::f[fu]=fv;
            res+=w;
            cnt++;
            if(cnt==n+ccnt-1) break;
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cout<<"!"<<endl;
    read(n);read(m);read(k);
    rep(i,1,m){
        int u,v,w;read(u);read(v);read(w);
        //ed.push_back({w,{u,v}});
        ED[i]={u,v,w};
    }edcnt=m;
    //cout<<"!"<<endl;
    //sort(ed.begin(),ed.end());
    sort(ED+1,ED+edcnt+1,cmp);
    //cout<<"!"<<endl;
    DSU::init();
    rep(i,0,m-1){
        // int u=ed[i].second.first,v=ed[i].second.second,w=ed[i].first;
        int u=ED[i+1].u,v=ED[i+1].v,w=ED[i+1].w;
        int fu=DSU::getfa(u),fv=DSU::getfa(v);
        if(fu!=fv){
            //printf("push:%d %d %d\n",u,v,w);
            e.push_back({w,{u,v}});
            DSU::f[fu]=fv;

        }
    }

    rep(i,1,k){
        read(val[i]);
        rep(j,1,n) read(c[i][j]);
        // ed.push_back({c[i][j],{i+n,j}});
    }
    /*
    sort(ed.begin(),ed.end());
    DSU::init();
    rep(i,0,m-1){
        int u=ed[i].second.first,v=ed[i].second.second,w=ed[i].first;
        int fu=DSU::getfa(u),fv=DSU::getfa(v);
        if(v>n) swap(u,v);
        if(u>n&&fu==fv){
            //c[u-n][v]=-1;
        }
        if(fu!=fv){
            //printf("push:%d %d %d\n",u,v,w);
            DSU::f[fu]=fv;
        }
    }
    */
    //cout<<"!"<<endl;
    ll ans=0x3f3f3f3f3f3f3f3f;
    rep(j,1,k){
        rep(v,1,n){
            se.push_back({c[j][v],{j+n,v}});
        }
    }
    rep(i,0,(int)e.size()-1) se.push_back(e[i]);
    sort(se.begin(),se.end());
    //cout<<"!"<<endl;
    rep(s,0,(1<<k)-1){
        ll ans1=0,ccnt=0;
        rep(j,1,k){
            ava[j]=((s>>(j-1))&1);
            ccnt+=ava[j];
            ans1+=1ll*ava[j]*val[j];
            //cout<<ava[j]<<endl;
        }
        //cout<<s<<" "<<solve()+ans1<<endl;
        ll temp=solve(ccnt)+ans1;
        //printf("%d:%d\n",s,temp-ans1);
        ans=min(ans,temp);
    }
    printf("%lld\n",ans);
    return 0;
}
//submit 15:56
