#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1) flag=1;
    }
    if(!flag){
        if(k==1) cout<<n;
        else if(k==0) cout<<n/2;
        else cout<<0;
    }
    else{
        bool f=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=1 && a[i]!=0) f=1;
        }
        if(!f){
            int ans1=0,ans2=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans1++;
                else ans2++;
            }
            if(k>1) cout<<0;
            else if(k==1) cout<<ans2;
            else cout<<ans1+(ans2/2);
        }
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
