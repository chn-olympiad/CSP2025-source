#include <bits/stdc++.h>
using namespace std;
int a[105];
int x;
int s[15][15];
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int c=1;
    int p=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            x=a[i];
        }
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(p%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                s[i][j]=a[c];
                c++;
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                s[i][j]=a[c];
                c++;
            }

        }
        p++;
    }
    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(s[i][j]==x)
            {
                cout<<i<<" "<<j;
                return 0;
            }

        }
    }
    return 0;
}
