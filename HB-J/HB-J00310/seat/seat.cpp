#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int f[15][15],a[104];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","d",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        f[i][1]=i;
        for(int j=2;j<=m;j++)
        {
            if(j%2==1)
            {
                f[i][j]=f[i][j-1]+2*i-1;
            }
            else
            {
                f[i][j]=f[i][j-1]+2*n-2*i+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(k==a[f[i][j]])
            {
                cout <<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
