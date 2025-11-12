#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long len=n*m;
    int a[len+5]={0};
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+len+1);
    int k=len;
    int map[15][15];
    bool xiwang=true;
    for(int j=1;j<=m;j++)
    {
        if(xiwang)
        {
            for(int i=1;i<=n;i++)
            {
                map[i][j]=a[k];
                k--;
            }
            xiwang=false;
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                map[i][j]=a[k];
                k--;
            }
            xiwang=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]==r)
            {
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
