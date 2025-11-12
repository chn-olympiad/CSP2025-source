#include<bits/stdc++.h>
using namespace std;
long long a,b[100005],k,qzh[100005];
int dp[1000005];
bool u=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>k;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        if(b[i]!=1){
            u=0;
        }
        if(i==1){
            qzh[1]=b[1];
        }
        if(i>1){
            qzh[i]=qzh[i-1]^b[i];
        }
    }
    if(a<=200000){

        for(int i=1;i<=a;i++){
            dp[i]=dp[i-1];
            for(int j=i;j>=1;j--){
                if(dp[j-1]+1==dp[i]){
                        break;
                    }
                int x;
                if(j==1){
                    x=qzh[i];
                }
                else{
                    x=qzh[i]^qzh[j-1];
                }
                if(x==k){
                    dp[i]=max(dp[i],dp[j-1]+1);
                }
            }

        }
        cout<<dp[a];
    }
    else{
        int num=b[1],ans=0;
        for(int i=2;i<=a;i++){
            if(num==k){
                ans++;
                num=b[i];
                continue;
            }
            if(num^b[i]==k){
                ans++;
                i++;
                num=b[i];
            }
            else{
                num=b[i];
            }
        }
        cout<<ans;
    }
    return 0;
}
