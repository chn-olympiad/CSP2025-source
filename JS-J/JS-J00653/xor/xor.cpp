#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,maxc=-9999999;
    cin>>n>>k;
    int lista[n];
    int dp[n]={0};
    int c;
    for(int i=0;i<n;i++){
        cin>>lista[i];

    }
    for(int i=0;i<n;i++){
            c=0;
        for(int j=i;j<n;j++){
            c=c^lista[j];
            if(i!=0)
                dp[j]=max(dp[i-1],dp[j]);
            if(c==k){
                if(i!=0)
                dp[j]=max(dp[j],dp[i-1]+1);
                else{
                    dp[j]=max(dp[j],1);
                }
                maxc=max(maxc,dp[j]);
            }

        }
    }

    cout<<maxc<<endl;

    return 0;
}
