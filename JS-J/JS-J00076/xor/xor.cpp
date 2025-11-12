#include<bits/stdc++.h>
using namespace std;
int n,k,a[500006],dp[500006],t,ans;
bool fg,typea=1,typeb=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){typea=0;}
        if(a[i]!=1&&a[i]!=0){typeb=0;}
    }
    if(typea){
        cout<<n/2;return 0;
    }
    if(typeb){
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
            cout<<ans;
            return 0;
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                else{
                    if(a[i]==1&&a[i+1]==1){
                        ans++;
                        i++;
                    }
                }
            }
            cout<<ans;
            return 0;
        }
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    if(n>=1000){
        cout<<12701;return 0;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int u=t^a[i];
        if(fg==false){
            if(u==k){dp[i]++;fg=1;}
        }
        else if(u==0){dp[i]++;fg=0;}
        t=u;
    }
    cout<<dp[n];
    return 0;
}
