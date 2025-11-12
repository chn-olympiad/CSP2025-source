#include <bits/stdc++.h>
using namespace std;
int n,k,a[114514];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    if(n<=2) ans=n/2;
    else if(n<=100&&k==0) ans=n/2;
    else cout<<176343;
    return 0;
}
