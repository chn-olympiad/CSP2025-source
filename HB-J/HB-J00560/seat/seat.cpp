#include<bits/stdc++.h>
using namespace std;
int a[121];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,j,x,n,m,k;
    cin>>n>>m>>a[1];
    if(n==1&&m==1)
    {
        cout<<"1 1";
        return 0;
    }
    k=a[1];
    for(i=2;i<=n*m;i++)
        cin>>a[i];
    for(i=n*m-1;i>1;i--)
        for(j=1;j<i;j++)
            if(a[j]<=a[j+1])
                swap(a[j],a[j+1]);
    for(i=1;i<=n*m;i++)
        if(k==a[i])
            x=i;
    if(n==1&&m<=10)
    {
        cout<<x+1<<" 1";
        return 0;
    }
    if(n<=10&&m==1)
    {
        cout<<"1 "<<x+1;
        return 0;
    }
    return 0;
}
