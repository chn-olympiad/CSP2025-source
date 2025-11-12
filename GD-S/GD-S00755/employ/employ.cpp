#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define ep emplace
#define pii pair<int,int>
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int maxn=510,maxN=(1<<18)+10,mod=998244353;
int n,m;
int a[maxn],c[maxn];
int dp[maxN][20];
int main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)   scanf("%1d",&a[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&c[i]);
    if(n==m){
        if(count(a+1,a+n+1,0)||count(c+1,c+n+1,0))  puts("0");
        else{
            int fac=1;
            for(int i=1;i<=n;i++)   fac=1ull*fac*i%mod;
            printf("%d\n",fac);
        }
        exit(0);
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int x=__builtin_popcount(i);
        for(int k=1;k<=n;k++)if(!(i&(1<<k-1))){
            for(int j=0;j<=x;j++){
                int jj=j+a[x+1];
                if(x-j>=c[k]&&a[x+1])   jj--;
                // printf("%d %d %d : %d\n",i,j,k,jj);
                (dp[i|(1<<k-1)][jj]+=dp[i][j])%=mod;
            }
        }
        // for(int j=0;j<=x;j++)   printf("%d %d : %d\n",i,j,dp[i][j]);
    }
    int ans=0;
    for(int i=m;i<=n;i++)   (ans+=dp[(1<<n)-1][i])%=mod;
    printf("%d\n",ans);
}