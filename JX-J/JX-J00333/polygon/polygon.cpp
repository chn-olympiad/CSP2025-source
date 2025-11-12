#include <bits/stdc++.h>
using namespace std;
constexpr int N=5005,Mod=998244353;
int n,mx,mul=1;
int dp[2*N],num[N];
long long ans=0,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int z=0;z<n;z++){
        cin>>num[z];
    }
    sort(num,num+n);
    mx=num[n-1];
    dp[0]=1;
    for (int z=0;z<n;z++){
        sum=0;
        for (int y=0;y<=num[z];y++){
            sum+=dp[y];
            sum%=Mod;
        }
        if (z>=2)ans+=((mul-sum)%Mod+Mod)%Mod;
        ans%=Mod;
        for (int y=2*mx;y>=num[z];--y){
            dp[y]=(dp[y]+dp[y-num[z]])%Mod;
        }
        mul<<=1;
        mul%=Mod;
    }
    cout<<ans<<'\n';
    return 0;
}
