#include<bits/stdc++.h>
using namespace std;
bool cup(int x,int y)
{
    return x>y;
}
int c[15][15];
int b[15][15];
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    int n,m;
    cin>>n>>m;
    int le=n*m;
    for(int i=1;i<=le;i++)
    {
        cin>>a[i];
    }
    int xiaoR=a[1];
    sort(a+1,a+le+1,cup);
    int len=0;

    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            for(int j=1;j<=n;j++)
            {
                len++;
                b[i][j]=a[len];

            }

        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                len++;
                b[i][j]=a[len];
            }

        }
    }
    int i1=0;
    int j1=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c[j][i]=b[i][j];
        }
    }
    int len1=0;
    for(int i=n;i>=1;i--)
    {
        len1++;
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==xiaoR)
            {
                cout<<j<<" "<<len1;
                return 0;
            }
        }
    }
    return 0;
}
