#include<bits/stdc++.h>
using namespace std;
const int MOD=998224353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+10],sumn[n+10]={},dp[n+10][n+10]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sumn[i]=sumn[i-1]+a[i];
    }
    int cnt=0;
    if(n==3){
        if(a[3]<sumn[2]) cnt=1;
        else cnt=0;
    }
    else if(sumn[n]==n){
        for(int i=3;i<=n;i++){
            cnt+=n-i+1;
        }
    }
    cout<<cnt;
    return 0;
}
