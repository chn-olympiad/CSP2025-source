#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a;
    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++){
        long long ai;
        cin>>ai;
        a.push_back(ai);
    }
    for(int i=1;i<=n;i++){
        bool is=0;
        int m=a[i-1];
        for(int j=i-1;j>0;j--){
            m^=a[j-1];
            if(m==k){
                is=1;
                m=j;
                break;
            }
        }
        if(is){
            dp[i]=max(dp[i-1],dp[m-1]+1);
        }else{
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
