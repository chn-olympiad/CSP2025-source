#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],m=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(n<=3){long long x;
    x=max(max(a[1],a[2]),a[3]);
    if((a[1]+a[2]+a[3])>2*x)cout<<'1';
    else cout<<'0';}
    else {
    for(int i=2;i<=n;i++)m*=i;cout<<m%9982445353;}
    return 0;
   }
