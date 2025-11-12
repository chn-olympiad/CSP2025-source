#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=(n-2);i++){
        ans+=(i*(n-1-i));
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
