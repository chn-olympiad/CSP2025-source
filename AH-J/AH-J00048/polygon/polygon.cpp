#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],cnt;
int main(void){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]*2<a[1]+a[2]+a[n])cout<<1;
    else cout<<0;
    return 0;
}
