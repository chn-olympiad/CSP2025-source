#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
for(int i=1;i<=n;i++){
    cin>>a[i];
}
    cout<<(a[n]+a[n-1])/2;
    return 0;
}
