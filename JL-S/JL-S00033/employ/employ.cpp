#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    long long ans=1;
    for(int i=2;i<=n;i++)ans=(ans*i)%998244353;
    cout<<ans;
    return 0;
}
