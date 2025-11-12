#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,sum=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    cout<<sum%998244353;
    return 0;
}
