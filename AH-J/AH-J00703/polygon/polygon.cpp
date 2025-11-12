#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[10010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    LL n;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n;
    return 0;
}
