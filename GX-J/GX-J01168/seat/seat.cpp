#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100]={0};
    int b[10][10]={0};
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int w=a[0];
    for(int i=0;i<n*m;i++)
    {
        for(int j=i+1;j<n*m;j++)
        {
            if(a[j]>a[i])
            {
                swap(a[j],a[i]);
            }
        }
    }
    for(int i=0;i<n*m;i++)
    {
        if((i/n)%2==0)
        {
            b[i%n][i/n]=a[i];
        }
        else if((i/n)%2==1)
        {
            b[n-1-(i%n)][i/n]=a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]==w)
            {
                cout<<j+1<<" "<<i+1;
            }
        }
    }
    return 0;
}
