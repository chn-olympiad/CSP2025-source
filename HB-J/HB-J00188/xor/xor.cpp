#include<bits/stdc++.h>
using namespace std;
int n,k,flag=1;
int a[1010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    if(k<=1&&flag==1)
    {
        cout<<n;
    }
    return 0;
}
