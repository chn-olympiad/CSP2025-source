#include<bits/stdc++.h>
#define ll long long
void read(int &x){
    x=0;bool neg=0;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=1;c=getchar();}
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(neg)x=-x;
}
#define se second
#define fi first
#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read2(x,y),read(z)
using namespace std;
int n,m,c[505],dp[262144][19],sum[505];
string s;
const int mod=998244353;
void slv(){
    read2(n,m);
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+'1'-s[i];
    for(int i=1;i<=n;i++)read(c[i]);
    dp[0][0]=1;
    for(int S=0;S<(1<<n);S++){
        int sz=__builtin_popcountll(S);
        for(int j=0;j<=sz;j++){
            for(int k=1;k<=n;k++){
                if(S>>(k-1)&1)continue;
                dp[S|(1<<(k-1))][j+(c[k]<=sz-j)]+=dp[S][j];
                dp[S|(1<<(k-1))][j+(c[k]<=sz-j)]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++)ans+=dp[(1<<n)-1][i],ans%=mod;
    cout<<ans<<endl;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    slv();
}   