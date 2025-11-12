#include <bits/stdc++.h>
using namespace std;
long long sum=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        sum*=i;
        sum%=998244353;
    }
    cout<<sum;
    return 0;
}
