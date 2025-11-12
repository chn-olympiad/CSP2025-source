/*
Author: Shunpower in CSP-S2025

我感到 soul cries
灵魂被 sold out
但不会懈怠 腐烂被嗅到
炙热的心才是最好解药
2025AMBITION with my freestyle
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fr1(i,a,b) for(int i=(a);i<=(b);i++)
#define fr2(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;
const int N=510;
const int mod=998244353;
int fac[N],ifac[N];
ll qpow(ll b,int p){
    if(!p) return 1;
    ll d=qpow(b,p>>1);
    if(p&1) return d*d%mod*b%mod;
    else return d*d%mod;
}
void init(int n=500){
    fac[0]=1;
    fr1(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n],mod-2);
    fr2(i,n-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int n,m;
char s[N];
int c[N];
void solve1(){
    int used=0;
    ll ans=1;
    int cnt=0;
    fr1(i,1,n){
        if(s[i]=='1'){
            int sum=0;
            fr1(j,1,n){
                if(c[j]<=i-1) sum++;
            }
            ans=1ll*ans*(sum-used)%mod;
            used++;
        }
        else cnt++;
    }
    ans=1ll*ans*fac[cnt]%mod;
    cout<<(fac[n]+mod-ans)%mod<<'\n';
}
int dp[2][1<<18][19];
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
void solve2(){
    dp[0][0][0]=1;
    int op=0;
    fr1(i,0,n-1){
        fr1(mask,0,(1<<n)-1){
            if(__builtin_popcount(mask)>i) continue;
            fr1(j,0,i){//前i天解决好，用了mask中的人，有j个人倒闭了
                if(!dp[op][mask][j]) continue;
                // cout<<i<<' '<<mask<<' '<<j<<":"<<dp[i][mask][j]<<endl;
                fr1(t,1,n){
                    if((mask>>t-1)&1) continue;
                    int tomask=mask|(1<<t-1);
                    int coef=(c[t]<=j||s[i+1]=='0');
                    add(dp[op^1][tomask][j+coef],dp[op][mask][j]);                    
                }
            }
        }
        fr1(mask,0,(1<<n)-1) fr1(j,0,n) dp[op][mask][j]=0;
        op^=1;
    }
    int sum=0;
    fr1(j,0,n-m) add(sum,dp[op][(1<<n)-1][j]);
    cout<<sum<<'\n';
}
int f[110][110][110];
int a[110];
int C(int n,int m){
    if(n<0||m<0||n>m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void solve3(){
    fr1(i,1,n) a[c[i]]++;
    f[1][1][0]=1;
    int sum=a[0];
    fr1(i,1,n){
        fr1(j,0,n){
            fr1(k,0,n){
                // cerr<<i<<' '<<j<<' '<<k<<":"<<f[i][j][k]<<endl;
                fr1(p,0,j){
                    if(j+p+1>n||k+p>n) continue;
                    add(f[i+1][j+1][k+p],1ll*f[i][j][k]*C(j+p-1,p-1)%mod*C(a[i]-p+sum-j,sum-j)%mod);
                }
            }
        }
        sum+=a[i];
    }
    int ans=0;
    fr1(i,m,n){
        fr1(j,0,n) add(ans,f[n+1][j][i]);
    }
    cout<<ans<<'\n';
}
#define shun cute
int main(){
#ifdef shun
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m;
    init();
    fr1(i,1,n) cin>>s[i];
    fr1(i,1,n) cin>>c[i];
    if(m==n){
        fr1(i,1,n){
            if(s[i]=='0'||c[i]==0){
                cout<<"0\n";
                return 0;
            }
        }
        cout<<fac[n]<<'\n';
        return 0;
    }
    if(m==1){
        solve1();
        return 0;
    }
    if(n<=18){
        solve2();
        return 0;
    }
    cout<<"0\n";
    return 0;
}
/*
我草这是干什么。
我T3 1log只跑了200ms不到。。
离谱dp

主播今天打了336分
T4这个s[i]=1的dp没写完。。
主播再也不相信了。

注意只考到18:30
last 15min, NOI Linux for big samples
never stop thinking
Stage 9
冷静。冷静。冷静。

g++ -O2 -std=c++14 a.cpp -o a
*/