#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ans=ans*i%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
