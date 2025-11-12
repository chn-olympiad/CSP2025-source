#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],num=0,m=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;long long ans=-0x3f3f3f3f;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        num+=a[i];
        ans=max(ans,a[i]);
    }
    if(num>2*ans) m++;
    cout<<m;
    return 0;
}
