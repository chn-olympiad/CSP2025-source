#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500010];
long long b0,b1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) b0++;
        if(a[i]==1) b1++;
    }
    if(k==1){
        cout<<b1;
        return 0;
    }
    if(k==0){
        cout<<b0+b1/2;
        return 0;
    }
    return 0;
}
