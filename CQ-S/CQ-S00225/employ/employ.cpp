#include<bits/stdc++.h>
using namespace std;
int n,m,f[1<<18][19],c[505];
string S;
const int mod=998244353;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>S;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    f[0][0]=1;
    for(int s=1;s<(1<<n);s++){
        int cnt=__builtin_popcount(s);
        for(int j=0;j<=cnt;j++){
            for(int k=1;k<=n;k++){
                if((s>>k-1)&1){
                    if(j&&(S[cnt-1]=='0'||j-1>=c[k]))f[s][j]=f[s][j]+f[s^(1<<k-1)][j-1];
                    if(S[cnt-1]=='1'&&j<c[k])f[s][j]=f[s][j]+f[s^(1<<k-1)][j];
                    while(f[s][j]>=mod)f[s][j]-=mod;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<=n-m;i++){
        sum+=f[(1<<n)-1][i];
        if(sum>=mod)sum-=mod;
    }
    cout<<sum;
    return 0;
}