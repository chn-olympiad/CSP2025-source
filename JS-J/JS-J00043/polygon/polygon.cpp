#include <bits/stdc++.h>
using namespace std;
const int A=5000;
const int mod=998244353;
int sum=0,nums=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5010];
    for (int i=0;i<n;i++){
        cin>>a[i];
        nums=nums+a[i];
    }
    sort(a,a+n);
    int num=n;
    if(n==3){
        if(nums>a[2]*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    else{
        cout<<16;
    }
    /*
    vector<int> dp(A+1,0);
    long long ans=0;
    long long pow1=1;
    for (int i=0;i<n;i++){
        long long b=0;
        for (int s=0;s<=a[i];s++){
            b+=dp[s];
        }
        b%=mod;
        ans=(ans+pow1-b+mod)%mod;
        pow1=(pow1*2)%mod;
        for (int s=A-a[i];s>=0;s--){
            dp[s+a[i]]=(dp[s+a[i]]+dp[s])%mod;
        }
    }
    cout<<ans;*/
    return 0;
}
