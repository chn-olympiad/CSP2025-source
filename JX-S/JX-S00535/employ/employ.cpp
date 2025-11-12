#include<bits/stdc++.h>
using namespace std;
long long sum=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        sum*=i;
        sum%=998244353;
    }
    if(m!=n) cout<<sum/m/2*n;
    else cout<<0;
    return 0;
}
