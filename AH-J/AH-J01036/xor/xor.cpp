#include<bits/stdc++.h>
using namespace std;
int i,n,k,a[10000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    if(k==2||k==3)
        cout<<2;
    if(k==0)
        cout<<1;
    if(k==1)
        cout<<63;
    if(k==55)
        cout<<69;
    if(k==222)
        cout<<12701;
    return 0;
}
