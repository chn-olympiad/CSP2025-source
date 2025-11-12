#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long num[3];
int mx=-1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    if(!(num[1]|num[2])==k) cout<<2;
    else cout<<1;
}
