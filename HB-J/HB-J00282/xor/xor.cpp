#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    bool f=false;
    int m=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            m++;
    }

    if(m%k==0)
        cout<<m/k;
    else
        cout<<m/k-1;
    return 0;
}
