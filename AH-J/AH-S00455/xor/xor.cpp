#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,a[500005],cnt[500005],s,sum,d[7007][7007],dp[7007];
bool kA,kB;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            kA=1;
        }
        if(a[i]>1){
            kB=1;
        }
        cnt[i]=cnt[i-1]^a[i];
    }
    if(kA==0&&k==0){
        cout<<n/2;
    }else if(k<=1&&kB==0){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                sum++;
            }else if(a[i]^s==k){
                s=0;
                sum++;
            }else{
                s=a[i]^s;
            }
        }
        cout<<sum;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if((cnt[j]^cnt[i-1])==k){
                    d[i][j]=1;
                    d[j][i]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(d[i][j]==1){
                    dp[i]=max(dp[i],dp[j-1]+1);
                }
            }
            dp[i]=max(dp[i],dp[i-1]);
        }
        cout<<dp[n];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
