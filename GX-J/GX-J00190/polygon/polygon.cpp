#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            for(int k=1;k<j;k++)
            {
                int p=max(a[i],a[j]);
                p=max(a[k],p);
                if(a[i]+a[j]+a[k]>p*2)
                {
                    s++;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
