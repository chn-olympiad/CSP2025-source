#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())

#define pb push_back
#define fi first
#define se second


using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;


const int N=1e5+5;
int n,c[3],tot=0,b[N];
PII v[N][3];

void solve(){
    cin>>n;
    rep(i,0,2) c[i]=0;
    rep(i,1,n){
        cin>>v[i][0].fi>>v[i][1].fi>>v[i][2].fi;
        v[i][0].se=1,v[i][1].se=2,v[i][2].se=3;
        sort(v[i],v[i]+3);reverse(v[i],v[i]+3);
    }

    int ans=0;
    rep(i,1,n)++c[v[i][0].se],ans+=v[i][0].fi;
    int tag=-1;
    rep(i,0,2)if(c[i]>n/2)tag=i;

    if(tag==-1)cout<<ans<<'\n';
    else{
        tot=0;
        rep(i,1,n)if(v[i][0].se==tag)b[++tot]=v[i][0].fi-v[i][1].fi;
        sort(b+1,b+1+tot);
        rep(i,1,c[tag]-n/2)ans-=b[i];
        cout<<ans<<'\n';
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);



    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int T;
    cin>>T;
    while(T--)solve();



    return 0;
}
