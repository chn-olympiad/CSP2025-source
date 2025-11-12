#include<bits/stdc++.h>
using namespace std;
int a[1100];
int b[100][100];
int x=1,y=1,cnt=1,t=0,p=0;
bool cmp(int c,int d)
{
    return c>d;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    p=n;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(i<=n)
        {
            y=i;
            x=cnt;
            b[x][y]=a[i];
        }
        else
        {
            t=i;
            p=n;
            if(t%n==0)
            {
                cnt=t/n;
            }
            else
            {
                cnt=(t/n)+1;
            }
            x=cnt;
            y=p;
            p--;
            b[x][y]=a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==r)
            {
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
