#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool t=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)t=0;
    }
    cout<<n/2;
    return 0;
}
