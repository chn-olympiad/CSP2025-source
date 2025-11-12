#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    int arr[n+1][m+1]={0},a[n*m+1]={0};
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            x=a[i];
        }
    }
    int pm=0;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(x==a[i])
        {
            pm=i;
        }
    }
    int k=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                if(k==pm)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
        else if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                if(k==pm)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}
