#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];
long long C[5005][5005];
void init(){
    C[1][1]=1;
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=i;j++){
            if(j==1)
                C[i][j]=i;
            else
                C[i][j]=(C[i-1][j]%MOD+C[i-1][j-1]%MOD)%MOD;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20){
        long long ans=0;
        for(int sta=0;sta<(1<<n);sta++){
            int sum=0,mx=0;
            for(int i=0;i<n;i++){
                if(sta&(1<<i)){
                    mx=max(mx,a[i+1]);
                    sum+=a[i+1];
                }
            }
            if(sum>mx*2)
                ans=(ans+1)%MOD;
        }
        cout<<ans%MOD<<endl;
    }
    else{
        long long ans=0;
        for(int i=3;i<=n;i++)
            ans=(ans+C[n][i]%MOD)%MOD;
        cout<<ans%MOD<<endl;
    }
    return 0;
}
