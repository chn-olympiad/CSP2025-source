#include <bits/stdc++.h>
using namespace std;
int a[500005];
int f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1)a[i]=a[i]^a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            f[i]=max(f[i],f[j]+((a[i]^a[j])==k));
        }
    }
    cout<<f[n];
    return 0;
}
