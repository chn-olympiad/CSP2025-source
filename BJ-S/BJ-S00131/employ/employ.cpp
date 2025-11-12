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
const int N=505;
const ll mod=998244353;
int n,m,c[N];
bool s[N];
ll ans;
int main(){
    CLOSE_TIE
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //freopen("employ/employ3.in","r",stdin);
    cin>>n>>m;
    bool flA=1;
    FOR(i,1,n){
        char c;
        cin>>c;
        s[i]=c-'0';
        flA=(flA&&s[i]);
    }
    FOR(i,1,m) cin>>c[i];
    if(m==1){
        if(!c[1]) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    if(flA){
        ans=1;
        FOR(i,1,n) ans=ans*i%mod;
        cout<<ans<<endl;
    }
    return 0;
}
