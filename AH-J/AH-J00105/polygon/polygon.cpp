#include<bits/stdc++.h>
using namespace std;
int a[5005],b,c;
void ljy(int s,int n)
{
    if(n>=b)
        return;
    if(s>a[n])
        c++;
    for(int i=n+1;i<b;i++)
        ljy(s+a[n],i);
    return;
}
int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>b;
    for(int i=0;i<b;i++)
        cin>>a[i];
    sort(a,a+b);
    for(int i=0;i<b-2;i++)
    {
        for(int j=i+1;j<b-1;j++)
        {
            for(int k=j+1;k<b;k++)
            {
                ljy(a[i]+a[j],k);
            }
        }
    }
    cout<<c%998244353;
    return 0;
}
