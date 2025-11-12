#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans = 1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ans *= i;
        ans %= 998244353;
    }
    cout<<ans<<endl;
    return 0;
}
