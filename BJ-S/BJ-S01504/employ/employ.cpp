#include<bits/stdc++.h>
using namespace std;using LL=int64_t;using LD=long double;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
#define endl '\n'
constexpr int MOD=998244353;
struct mint{
    int x;
    mint(int _x=0):x(_x%MOD){}
    mint(LL _x):x(_x%MOD){}
    mint operator+(mint m){
        return x+m.x;
    }
    mint&operator+=(mint m){
        return *this=*this+m;
    }
    mint&operator++(){return *this+=1;}
    mint operator*(mint m){
        return LL(x)*m.x;
    }
    mint&operator*=(mint m){
        return *this=*this*m;
    }
};
ostream&operator<<(ostream&o,mint m){return o<<m.x;}
auto freo(string s){
    string in=s+".in";
    string out=s+".out";
    return make_pair(
        freopen(in.c_str(),"r",stdin),
        freopen(out.c_str(),"w",stdout)
    );
}
int n,m;string s;
vector<int>c;
namespace DP{
int main(){
    vector<vector<mint>>dp(1<<n,vector<mint>(n+1));
    dp[0][0]=1;fu(s,0,1<<n){
        int k=__builtin_popcount(s);
        bool sg=::s[k]=='1';
        f(j,0,k){
            fu(i,0,n)if(~s>>i&1){
                int t=s^(1<<i);
                bool g=sg&&k-j<c[i];
                dp[t][j+g]+=dp[s][j];
            }
        }
    }
    auto ansdp=dp.back();
    mint ans=0;
    f(j,m,n)ans+=ansdp[j];
    cout<<ans<<endl;
    return 0;
}
}
//WA
namespace A{
int main(){
    mint ans=1;
    f(i,1,n)ans*=i;
    cout<<ans<<endl;
    return 0;
}
}
int main(){
    freo("employ");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    c.resize(n);for(int&x:c)cin>>x;
    if(n<=18)return DP::main();
    // if(count(s.begin(),s.end(),'1')==n)return A::main();
    cout<<0<<endl;
    return 0;
}
//pass sample 1,2:15:54
