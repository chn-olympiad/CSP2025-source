#include<bits/stdc++.h>
using namespace std;
long long int dp[5005];
int brr[5005];
bool b=true;
long long int ans=1,c=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>brr[i];
        if(brr[i]!=1){
            b=false;
        }
    }
    sort(brr,brr+n);
    if(brr[0]+brr[1]<brr[2]){
        ans--;
    }
    if(b){
        for(int i=n;i>3;i--){
            c*=i;
            ans+=c;
            c=c%1000000000;
            ans=ans%998244353;
        }
    }
    cout<<ans;

    return 0;
}
