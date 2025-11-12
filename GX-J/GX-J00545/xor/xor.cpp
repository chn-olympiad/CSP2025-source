#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long n,k,a[200005],dp[200005],ans=0;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n,k,a;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]^a[j]==k){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[n];

    return 0;
}
