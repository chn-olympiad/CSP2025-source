#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(k==0)cout<<a[n]-a[1]-2;
    else cout<<a[n]-a[1]-1;
    return 0;
}
