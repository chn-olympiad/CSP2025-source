#include <bits/stdc++.h>
using namespace std;
int n,kk;
int a[500005];
int dp[1005][1005];
bool isok(int l,int r){
    string s1;
    int k=a[l];
    while(k){
        s1+=((k%2)+'0');
        k/=2;
    }

    for(int i=l+1;i<=r;i++){
        string s2;
        k=a[i];
        while(k){
            s2+=((k%2)+'0');
            k/=2;
        }
        if(s1.size()<s2.size()){
            swap(s1,s2);
        }
        for(int i=s2.size()-1;i>=0;i--){
            if(s1[i]==s2[i])s1[i]=0;
            else s1[i]=1;
        }
    }
    int s=1;
    int sum=0;
    for(int i=s1.size()-1;i>=0;i--){
        sum+=(s*s1[i]);
        s*=2;
    }
    return(sum==kk);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>kk;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(isok(i,j)==0){
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
                dp[i][j]=dp[i-1][j]+1;
        }
    }
    cout<<dp[n][n];
    return 0;
}
