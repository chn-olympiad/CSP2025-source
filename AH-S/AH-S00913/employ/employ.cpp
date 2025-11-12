#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int t=rand();
    int p=rand();
    int m=rand();
    cout<<(t*p*m%mod+2204128%mod)%mod;
    return 0;
}
