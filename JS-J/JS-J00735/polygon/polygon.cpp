#include<bits/stdc++.h>
using namespace std;
int a[5005],b[100001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    b[0]=1;
    for(int i=1;i<=n;i++){
        int cur=0;
        // cout<<i<<"\n";
        // for(int j=0;j<=20;j++){
        //     cout<<b[j]<<" ";
        // }
        // cout<<"\n";
        for(int j=10001;j>=0;j--){
            if(j>a[i]) {
                cur+=b[j];
                cur%=998244353;
            } 
            b[min(j+a[i],10001)]+=b[j];
            b[min(j+a[i],10001)]%=998244353;
        }
        // for(int j=0;j<=20;j++){
        //     cout<<b[j]<<" ";
        // }
        // cout<<"\n";
        ans+=cur;
        ans%=998244353;
    }
    cout<<ans;
}