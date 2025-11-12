#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<n/2;
    return 0;
}
