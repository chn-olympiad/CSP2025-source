#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[150]={};
    int now=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[now];
            now++;
        }
    }
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int s[15][15]={};
    int xz=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=m;j++)
            {
                s[i][j]=a[xz];
                xz++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                s[i][j]=a[xz];
                xz++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==x)
            {
                cout<<i<<" "<<j;
            }
        }
    }
    /*
    if(s%n==0)
    {
        cout<<s/n<<" ";
    }
    else
    {
        cout<<s/n+1<<" ";
    }*/



    return 0;
}
