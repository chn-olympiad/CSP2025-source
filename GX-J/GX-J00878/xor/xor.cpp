#include<bits/stdc++.h>
using namespace std;
int n,k,a[200000],f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) f++;
    }
    cout<<f;
    return 0;
}
