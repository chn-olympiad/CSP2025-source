#include<bits/stdc++.h>
using namespace std;
int n,a[901000],k,qz[901000];
int cnt(int i,int j){
    return qz[j]^qz[i-1];
}
int dp[900010];
unordered_map<int,int>ma;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qz[i]=a[i]^qz[i-1];
    }
    ma[0]=1;
    for(int i=1;i<=n;i++){
        /*for(int j=1;j<=i;j++){
                //di^dj==k
                //dj=k^di
            if(cnt(j,i)==k){
                dp[i]=max(dp[i],dp[j-1]+1);
            }

        }
        dp[i]=max(dp[i-1],dp[i]);
        */
        dp[i]=max(dp[i-1],ma[qz[i]^k]);
        ma[qz[i]]=max(ma[qz[i]],dp[i]+1);

        //cout<<dp[i]<<" "<<qz[i]<<" = "<<ma[qz[i]^k]<<" "<<a[i]<<endl;
        int x=k;
        //cout<<(qz[i]^k)<<endl;
    }
    cout<<dp[n];
	return 0;
}
/*
4 2
2 1 0 3
4 0
2 1 0 3
4 3
2 1 0 3

 10 8
87 43 47 56 44 45 63 76 12 4  69
*/
