#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,n;
    cin>>a>>n;
    long long ans;
    for(int i=0;i<=n*a;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;


}
