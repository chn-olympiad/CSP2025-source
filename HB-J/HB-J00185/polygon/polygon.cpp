#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[5004];
    long long cnt=0,mod=998244353;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n==3){
        if(a[0]+a[1]>a[2]) cout<<"1";
        else cout<<"0";
        return 0;
    }
    for(int i=3;i<=n;i++){
        long long p=1,q=1;
        for(int j=i;j>0;j--){
            p*=j;
            p%=mod;
        }
        for(int j=n,s=1;s<=i;j--,s++){
            q*=j;
            q%=mod;
        }
        cnt+=(q/p);
        cnt%=mod;
    }
    cout<<cnt;
    return 0;
}
