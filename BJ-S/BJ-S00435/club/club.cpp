#include<bits/stdc++.h>
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
const int N=1e5+10;
int T,n,a[N][3],now[4],mx[N];
priority_queue<pair<int,pair<int,int> > > q;
vector<int> v;
void solve(){
    read(n);
    now[0]=now[1]=now[2]=now[3]=0;
    rep(i,1,n) read(a[i][0]),read(a[i][1]),read(a[i][2]);
    rep(i,1,n){
        int maxv=max({a[i][0],a[i][1],a[i][2]});
        if(maxv==a[i][0]) now[0]++,mx[i]=0;
        else if(maxv==a[i][1]) now[1]++,mx[i]=1;
        else if(maxv==a[i][2]) now[2]++,mx[i]=2;
    }
    int id=-1,ans=0,need=0;
    rep(i,1,n) ans+=a[i][mx[i]];
    rep(i,0,2) if(now[i]*2>n) id=i,need=now[i]-n/2;
    if(id==-1){
        printf("%d\n",ans);
        return;
    }
    // printf("%d %d\n",need,id);
    v.clear();
    rep(i,1,n){
        if(mx[i]!=id) continue;
        int maxval=-0x3f3f3f3f;
        rep(j,0,2){
            if(j==id) continue;
            maxval=max(maxval,a[i][j]-a[i][id]);
        }
        v.push_back(maxval);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<(int)v.size();++i){
        if(!need) break;
        need--;
        ans+=v[i];
    }
    printf("%d\n",ans);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);while(T--) solve();
    return 0;
}
