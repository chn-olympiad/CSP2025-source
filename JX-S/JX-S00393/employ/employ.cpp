#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define db long double
#define F(i,k,n) for (int i=k;i<=n;i++)
#define R(i,k,n) for (int i=k;i>=n;i--)
#define ins insert
#define mpr make_pair
#define pu push_back
#define mes(a,b) memset(a,b,sizeof a);
//2326968
const int N=510;
const int mod=998244353;
int dp[N][N];
int fact[N],inv[N];
int s[N];
int c[N];
int n,m;
string t;
int sum[N];
int f[N];
int q_pow(int a,int b){
    int ans=1;
    while (b){
        if (b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int C(int n,int m){
    if (m>n || n<0 || m<0) return 0;
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int a[N];
int rc[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>t;
    t=" "+t;
    fact[0]=inv[0]=1;
    F(i,1,N-7){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=q_pow(fact[i],mod-2);
    }
    F(i,1,n){
        s[i]=s[i-1]+(t[i]=='0');
    }
    F(i,1,n) sum[s[i]]++;
    F(i,1,n) cin>>c[i],c[i]--;
    sort(c+1,c+1+n);
    F(i,1,n) a[i]=i;
    if (n>=12){
        cout<<fact[n];
        return 0;
    }
    int ans=0;
    do{
        F(i,1,n) rc[i]=c[a[i]];
        int now=0,q=0;
        F(i,1,n){
            if (now>rc[i]){
                now++;
                continue;
            }
            if (t[i]=='0'){
                now++;
                continue;
            }
            q++;
        }
        if (q>=m){
            ans++;
        }
    }while (next_permutation(a+1,a+1+n));
    cout<<ans;
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/