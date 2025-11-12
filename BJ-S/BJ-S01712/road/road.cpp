#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
struct way1{
    ll from,to,len;
    bool operator<(const way1 &o)const{
        return len>o.len;
    }
};
bool cmp(way1 a,way1 b){
    return a.len<b.len;
}
struct town1{
    ll c,a[10005];
};
ll n,m,k,allans;
way1 way[1000005];
town1 town[15];
ll fa[10005];
ll getfa(ll now){
    if(fa[now]==now){
        return now;
    }
    return fa[now]=getfa(fa[now]);
}
void together(ll x,ll y){
    fa[getfa(x)]=getfa(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    allans=1e18;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>way[i].from>>way[i].to>>way[i].len;
    }
    sort(way+1,way+m+1,cmp);
    way[m+1].from=0;
    way[m+1].to=0;
    way[m+1].len=1e18;
    ll t114514=1;
    for(int i=1;i<=k;i++){
        cin>>town[i].c;
        if(town[i].c!=0){
            t114514=0;
        }
        for(int j=1;j<=n;j++){
            cin>>town[i].a[j];
        }
    }
    if(t114514==1){
        ll ans1=0,times=0;
        priority_queue<way1> newway;
        for(int i=1;i<=k;i++){
            ans1+=town[i].c;
            times++;
            for(int j=1;j<=n;j++){
                newway.push({i+n,j,town[i].a[j]});
            }
        }
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        ll nowpos=1;
        for(int i=1;i<=m+times*n;i++){
            if(newway.empty()){
                ll x1=way[nowpos].from;
                ll y1=way[nowpos].to;
                ll mon=way[nowpos].len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                nowpos++;
                continue;
            }
            way1 newtop=newway.top();
            if(way[nowpos].len<newtop.len){
                ll x1=way[nowpos].from;
                ll y1=way[nowpos].to;
                ll mon=way[nowpos].len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                nowpos++;
            }else{
                ll x1=newtop.from;
                ll y1=newtop.to;
                ll mon=newtop.len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                newway.pop();
            }
        }
        cout<<ans1<<endl;
        return 0;
    }
    for(int pos=0;pos<(1<<k);pos++){
        ll ans1=0,times=0;
        priority_queue<way1> newway;
        for(int i=1;i<=k;i++){
            if((pos>>(i-1))&1){
                ans1+=town[i].c;
                times++;
                for(int j=1;j<=n;j++){
                    newway.push({i+n,j,town[i].a[j]});
                }
            }
        }
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        ll nowpos=1;
        for(int i=1;i<=m+times*n;i++){
            if(newway.empty()){
                ll x1=way[nowpos].from;
                ll y1=way[nowpos].to;
                ll mon=way[nowpos].len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                nowpos++;
                continue;
            }
            way1 newtop=newway.top();
            if(way[nowpos].len<newtop.len){
                ll x1=way[nowpos].from;
                ll y1=way[nowpos].to;
                ll mon=way[nowpos].len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                nowpos++;
            }else{
                ll x1=newtop.from;
                ll y1=newtop.to;
                ll mon=newtop.len;
                if(getfa(x1)!=getfa(y1)){
                    ans1+=mon;
                    together(x1,y1);
                }
                newway.pop();
            }
        }
        allans=min(allans,ans1);
    }
    cout<<allans<<endl;
    return 0;
}
