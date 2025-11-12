#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,i,as=0,st=0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=0) st++;
    }
    if(k==1)
    {
        cout<<st;
        return 0;
    }
    if(k==0)
    {
        cout<<n-st;
        return 0;
    }
    as=n/k;
    cout<<as;
    return 0;
}
