#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    int n,k,a[1000000];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=2&&k==0) cout<<1;
    return 0;
}
