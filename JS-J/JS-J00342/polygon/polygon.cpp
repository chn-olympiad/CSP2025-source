#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN=5e3+8;
const int mod=998244353;
ifstream fin("polygon.in");
ofstream fout("polygon.out");
int n,a[MAXN];
LL dp[MAXN][MAXN],ans;
int main(){
    fin>>n;
    for(int i=1;i<=n;i++)fin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)dp[i][a[i]]=1;
    for(int i=1;i<=n;i++){
        ans=ans*2%mod;
        for(int j=0;j<a[i];j++)ans=(ans+dp[i-1][j])%mod;
        for(int j=0;j<MAXN-1;j++){
            dp[i][j]+=dp[i-1][j];
            if(j+a[i]<MAXN-1)dp[i][j]=(dp[i][j]+dp[i-1][j+a[i]])%mod;
        }
    }fout<<ans;
}
