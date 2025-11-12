#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,z=0,c;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<=n-1;i++) cin>>a[i];
    for(int j=0;j<=n-1;j++){
    for(int i=0;i<=n-j-1;i++){
        for(int k=0;k<=j;k++) c+=a[i+k];
        if(c==k) z++;
        else if(c%2==0)z++;
    }
    }
    cout<<z/2-1;
    return 0;
}
