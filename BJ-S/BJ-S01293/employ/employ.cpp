#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int jc(int x){
    int ans=1;
    for(int i=1;i<=x;i++){
        ans*=i;
        ans%=mod;

    }
    return ans;
}
int A(int n,int m){
    int ans=jc(n),bns=jc(n-m);
    return ans/bns;
}
int C(int n,int m){
    int ans=A(n,m),bns=A(m,m);
    return ans/bns;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<C(n,m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

