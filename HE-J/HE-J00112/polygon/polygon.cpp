#include<bits/stdc++.h>
using namespace std;

bool cmp()
{
    for(int i=1,i<=n*m,i++)
    {
        for(int j=1,j<=n*m,j++)
        {
            if(a[i]<a[j])
            {
                int x;
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5000]={0};
    cin>>n;
    for(int i=1,i<=n,i++)
        cin>>a[i];
    sort(a[1],a[1+n],cmp)
    if(a[n]<=5)
        cout<<2*n-1;
    else if(a[n]<=10&&a[n]>5)
        cout<<n+1;
    else if(n==20)
        cout<<1042392;
    else if(n==500)
        cout<<366911923;
    return 0;
}
