#include<bits/stdc++.h>
using namespace std;
int a[500005],k,n,f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        int l=a[i];
        if(a[i]==k){
            f[i]++;
            continue;
        }
        for(int j=i-1;j>0;j--){
            l^=a[j];
            if(l==k){
                f[i]=max(f[i],f[j-1]+1);
                break;
            }
        }
    }
    cout<<f[n];
    return 0;
}
