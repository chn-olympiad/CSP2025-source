#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    int n,m;
    long long ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    long long ccb=1;
    for(int j=i;j>=1;j++){
    ccb=ccb*j;

    }
    ans+=ccb;
    }
    cout<<ans%mod;
}
