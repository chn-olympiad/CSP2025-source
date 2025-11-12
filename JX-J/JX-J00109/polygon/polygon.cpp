#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long b[5010];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]<=a[0]||a[1]+a[0]<=a[2]||a[0]+a[2]<=a[1]){
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            return 0;
        }
    }

    sort(b,b+n);
    vector<long long> dp(n+1,0);
    dp[0]=0;
    dp[1]=0;
    for(long long i=2;i<n;i++){
        if(b[i-1]+b[i-2]+b[i]>2*max((b[i-2],b[i-1]),b[i])){
            dp[i]=dp[i-1]+dp[i-2]+1;
        }
        else dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n-1]%998244353<<endl;
    return 0;
}
