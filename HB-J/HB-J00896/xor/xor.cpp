#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a[1000];
   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n%k==0){
        cout<<n/k;
    }
    else{
        cout<<(n-k)/k;
    }
    return 0;
}
