#include<bits/stdc++.h>
using namespace std;
long long k,n,s[500010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cout<<n/k;
    return 0;
}
