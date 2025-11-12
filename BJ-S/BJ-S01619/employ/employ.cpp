#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long mod=998244353;
long long fact(long long x){
    long long ret=1;
    for(long long i=1;i<=x;i++)ret=(ret*i)%mod;
    return ret;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    string s;
    cin>>n>>m>>s;
    vector<long long>c(n+1);
    for(long long i=1;i<=n;i++)cin>>c[i];
    vector<vector<long long>> nCr(n+1,vector<long long>(n+1,0));//nCr[i][j]=C _ i ^ j (i>=j)
    for(long long i=1;i<=n;i++){
        nCr[i][i]=nCr[i][0]=1;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<i;j++){
            nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
        }
    }
    cout<<(((nCr[n][m]*nCr[s.size()][m])%mod)*fact(m))%mod;
    return 0;
}
