#include<bits/stdc++.h>
using namespace std;
int nxor[10001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n%2==1) cout<<(n-1)/2;
    if(n%2==0) cout<<n/2;
    return 0;
}
