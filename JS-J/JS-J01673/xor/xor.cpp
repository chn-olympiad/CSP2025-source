#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],f[500005],x[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(a[i]==k)f[i]++;
        int pos=x[b[i]^k];
        if(b[pos]^b[i]==k)f[i]=max(f[i],f[pos]+1);
        x[b[i]]=i;
    }
    cout<<f[n];
    return 0;
}
//nan dao wo zhen shi tian cai?
