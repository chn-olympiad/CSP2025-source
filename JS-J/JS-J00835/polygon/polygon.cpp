#include <bits/stdc++.h>

using namespace std;
long long dp[1000],a[10000],sum[1000],f[100000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=90000;j>=a[i];j--){
            if(j>a[i]*2+1&&f[j-a[i]]!=0){
                f[j]=f[j-a[i]]+1;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=90000;i++){
        if(f[i]>3){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
