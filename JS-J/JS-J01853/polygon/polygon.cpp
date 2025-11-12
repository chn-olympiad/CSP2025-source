#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[5010];
long long f(int i,int n,long long s){
    if(i==n-1){
        if(s+a[i]>a[n])return 1;
        return 0;
    }
    return f(i+1,n,s+a[i])%mod+f(i+1,n,s)%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long s=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=2;i<n;i++){
        s=(s+f(0,i,0))%mod;
    }
    cout<<s;
    return 0;
}
