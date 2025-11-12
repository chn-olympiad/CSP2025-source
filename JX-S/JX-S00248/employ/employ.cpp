#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int a(int x){
    int res=1;
    for(int i=1;i<=n;i++)res=(res*i)%mod;
    return res%mod;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
    }
    cout<<a(n);
    return 0;
}
