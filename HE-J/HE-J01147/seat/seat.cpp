#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    int a[n][m];
    cin>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]>a[i][j+1])
            {
                int k;
                k=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=k;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x>a[i][j])
            {
                if(i%2==0)
                {
                    cout<<i<<" "<<m-j;
                    break;
                }
                else
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
