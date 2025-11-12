#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
    int x=0,f=1; char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x*f;
}
const int N=505,mod=998244353;
int s[N],c[N],n,m,p[N];
int inv(int x){
    int k=mod-2,res=1;
    while(k){
        if(k&1) res=res*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return res;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    n=read(),m=read();
    string s;
    cin>>s;
    int f=1;
    rep(i,0,s.length()-1){
        f=f&(s[i]-'0');
    }
    // int cnt=0;
    rep(i,1,n) cin>>c[i];
    // cnt+=c[i]==0;
    rep(i,1,n) p[i]=i;
    int ans=0;
    do{
        // rep(i,1,n) cout<<p[i]<<" ";
        int cnt=0;
        rep(i,1,n){
            if(cnt>=c[p[i]]){
                cnt++;
                continue;
            }
            if(s[i-1]=='0') cnt++;
        }
        if(cnt<=n-m) ans++;
        // cout<<cnt;
        // cout<<endl;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}