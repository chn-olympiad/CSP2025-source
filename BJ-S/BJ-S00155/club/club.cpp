#include<bits/stdc++.h>
#define int long long
using namespace std;

inline long long read(){
    long long n=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

struct xal{
    int x,a[3],l;
    friend bool operator<(xal g,xal h){
        return g.l<h.l;
    }
};

int n,ans;
vector<xal>v[3];

void check(const int b){
    sort(v[b].begin(),v[b].end());
    for(int i=0,ni=v[b].size()-(n>>1);i<ni;++i){
        ans-=v[b][i].l;
    }
    return;
}

signed mian(){
    n=read();ans=0;
    v[0].clear();
    v[1].clear();
    v[2].clear();
    for(int i=1;i<=n;++i){
        int x[]={read(),read(),read()};
        for(int j=0;j<3;++j){
            if(x[(j+1)%3]<=x[j]&&x[(j+2)%3]<=x[j]){
                v[j].push_back({x[j],x[0],x[1],x[2],x[j]-max(x[(j+1)%3],x[(j+2)%3])});
                ans+=x[j];
                break;
            }
        }
    }
    for(int i=0;i<3;++i){
        if(v[i].size()>(n>>1)){
            check(i);
        }
    }
    cout<<ans<<"\n";
    return 0;
}

signed main(){
    //freopen("club5.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int Q=read();
    while(Q--){
        mian();
    }
    return 0;
}
