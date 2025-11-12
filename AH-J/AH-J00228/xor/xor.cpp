#include<iostream>
#include<cstdio>
using namespace std;
int a[500005],dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        bool f=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                f=1;
                break;
            }
        }
        if(!f){
            cout<<n/2;
            return 0;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                }
                if(a[i]==1&&a[i-1]==1){
                    ans++;
                    if(a[i+1]==1){
                        i++;
                    }
                }
            }
            cout<<ans;
            return 0;
        }
    }else if(k==1)
    {

        bool f=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
            if(a[i]>1){
                f=1;
                break;
            }
        }
        if(!f){
            cout<<ans;
            return 0;
        }
    }
    int xors=0;//^
    for(int i=1;i<=n;i++){
        xors=0;
        for(int j=i;j<=n;j++){
            xors^=a[j];
            if(xors==k){
                for(int l=1;l<i;l++){
                    dp[j]=max(dp[j],dp[l]);
                }
                dp[j]++;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
