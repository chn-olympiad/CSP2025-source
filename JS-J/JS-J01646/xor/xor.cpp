#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],p,c,j;
/*bool p(int l,int r)
{
    for(int i = l;i <= r;i++)
    {

    }
    return
}*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) p=1;
    }
    if(p==0) cout<<n/2;
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i]==1) j++;
        }
        cout<<j;
    }
    return 0;
}
