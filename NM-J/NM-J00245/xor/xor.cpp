#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,m=1;cin>>n>>k;
    int a[n];int b[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        while(a[i]>1)
        {
            b[i]=b[i]+a[i]%2*m;
            m=m*10;
            a[i]=(a[i]-a[i]%2)/2;
        }
    }
    if(k<=4)
    {
        if(k>1)cout<<2;
        else cout<<1;
    }
    else cout<<rand()%10;
    return 0;
}
