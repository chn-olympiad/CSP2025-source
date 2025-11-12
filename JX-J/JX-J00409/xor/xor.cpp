#include<bits/stdc++.h>
using namespace std;
int a[50010],n;
int xorNOI(int k)
{
    int l=1,r=n;
    return (l+r)/2;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<xorNOI(k);
    return 0;
}
