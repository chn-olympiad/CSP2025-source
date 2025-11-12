#include <bits/stdc++.h>
using namespace std;
int a[23],dp[23][23];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    int nax=-1;
    int sum=0;
    if(n==3){
        for(int i =1;i<=n;i++){
            sum+=a[i];
            nax=max(nax,a[i]);
        }
        if(sum>2*nax){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }

    return 0;
}
