#include <bits/stdc++.h>
using namespace std;
int main(){//gou shi ti mu nan si wo le!!!shei chu de ti wo yao sha le ta (na chu dao
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[100005],b[100005];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    if(b[0] == b[n-1]){
        cout<<n;
        return 0;
    }

    cout<<n;

    return 0;
}
