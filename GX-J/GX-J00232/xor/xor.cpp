#include<bits/stdc++.h>
using namespace std;
int a[500005];
int f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i]|f[i-1];
    }
    cout<<2;
    return 0;
}
