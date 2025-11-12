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
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,id,c,r;
    cin>>n>>m;
    int a[101]={0};
    for(int i=1,i<=n*m,i++)
        cin>>a[i];
    k=a[1];
    sort(a[1],a[1+n*m],cmp)
    for(int z=1,z<=n*m,z++)
    {
        if(a[z]=k)
        {
            id=z;
            z=n*m+1;
        }

    }
    if(id%n==0)
        c=id/n;
    else c=id/n + 1;
    if(c%2==1)
        r=id%n;
    else r=n+1-id%n;
    cout<<c<<" "<<r;
    return 0;
}
