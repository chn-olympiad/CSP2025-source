#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(k==0) cout<<(n+1)/2;
    else cout<<n/k;
    return 0;
}
