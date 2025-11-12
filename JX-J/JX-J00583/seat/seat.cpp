#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[11][11];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                sum++;
                b[i][j]=a[sum];
            }
        }
        else for(int j=n;j>=1;j--)
             {
                sum++;
                b[i][j]=a[sum];
             }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[j][i]==r)
                cout<<j<<" "<<i;
        }
    }
    return 0;
}
