#include <bits/stdc++.h>
using namespace std;
int n,a[500005],f[500005];
long long k;
int qiu(int x,int y)
{
    int t=1,sum=a[x];
    while(t<=y-x)
    {
        sum^=a[x+t];
        t++;
    }
    return sum;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(qiu(j,i)==k)
            {
                f[i]=max(f[i],f[j-1]+1);
            }else{
                f[i]=max(f[i],f[j-1]);
            }
        }
    }
    cout<<f[n];
    return 0;
}
