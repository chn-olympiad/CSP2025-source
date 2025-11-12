#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a),EEE##i=(b);i<=EEE##i;i++)
#define REV(i,a,b) for(int i=(a),EEE##i=(b);i>=EEE##i;i--)
#define CLOSE_TIE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define psbk push_back
#define endl '\n'
template<typename T>
void _outval(string s,int p,const T &t){cout<<s.substr(p,s.size()-p)<<'='<<t<<endl;}
template<typename T,typename... Args>
void _outval(string s,int p,const T &t,const Args &...rest){
    string n;
    while(s[p]!=',') n+=s[p++];
    cout<<n<<'='<<t<<' ';
    _outval(s,p+1,rest...);
}
#define outval(...) _outval(#__VA_ARGS__,0,__VA_ARGS__)
#define outarr(aaa,be,ed)\
{cout<<(#aaa)<<": ";\
FOR(iiii,be,ed) cout<<'['<<iiii<<"]="<<aaa[iiii]<<(iiii==ed?endl:' ');}
const int N=200+5;
const int rN=1e5+5;
struct AAA{ll x,y,z;}a[rN];
int T,n,lim;
ll ans,f[N][N],tf[N][N],g[N],tg[N];
void solve(){
    cin>>n;
    ll mxx=0,mxy=0,mxz=0;
    ans=0;
    FOR(i,1,n){
        cin>>a[i].x>>a[i].y>>a[i].z;
        mxx=max(mxx,a[i].x);
        mxy=max(mxy,a[i].y);
        mxz=max(mxz,a[i].z);
    }
    lim=n/2;
    if(!mxy&&!mxz){
        sort(a+1,a+n+1,[](AAA a,AAA b){return a.x>b.x;});
        FOR(i,1,lim) ans+=a[i].x;
        cout<<ans<<endl;
        return;
    }else if(!mxz){
        FOR(p,1,n){
            FOR(i,0,p){
                if(i>lim) break;
                int j=p-i;
                if(j>lim) continue;
                g[i]=max((!i?0:tg[i-1]+a[p].x),(!j?0:tg[i]+a[p].y));
            }
            FOR(i,0,p) tg[i]=g[i],g[i]=0;
        }
        FOR(i,0,lim) ans=max(ans,tg[i]);
        cout<<ans<<endl;
        return;
    }
    if(n>200){
        FOR(i,1,n) ans+=max({a[i].x,a[i].y,a[i].z});
        cout<<ans<<endl;
        return;
    }
    memset(f,0,sizeof f); memset(tf,0,sizeof tf);
     FOR(p,1,n){
        FOR(i,0,p){
            if(i>lim) break;
            FOR(j,0,p-i){
                if(j>lim) break;
                int k=p-i-j;
                if(k>lim) continue;
                f[i][j]=max({(!i?0:tf[i-1][j]+a[p].x),(!j?0:tf[i][j-1]+a[p].y),(!k?0:tf[i][j]+a[p].z)});
            }
        }
        FOR(i,0,p)
            FOR(j,0,p) tf[i][j]=f[i][j],f[i][j]=0;
        //outval(p); FOR(i,0,p) outarr(tf[i],0,p);
     }
     FOR(i,0,lim)
        FOR(j,0,lim){
            int k=n-i-j;
            if(k<=lim){
                ans=max(ans,tf[i][j]);
                //outval(i,j,k,f[n][i][j]);
            }
        }
    cout<<ans<<endl;

}
int main(){
    CLOSE_TIE
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //freopen("club/club4.in","r",stdin);
    cin>>T;
    while(T--) solve();
    return 0;
}
