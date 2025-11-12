#include<bits/stdc++.h>
using namespace std;
int s[10][10];
int a[101];
int n,m,flag;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    flag=a[1];
    sort(a,a+n*m+1,cmp);
    int c=0,i=1;
    while(i<=n)
    {
        if(i%2==1)
            for(int j=1;j<=m;j++)
            {
                s[i][j]=a[c];
                c++;
            }
        else
            for(int j=m;j>=1;j--)
            {
                s[i][j]=a[c];
                c++;
            }
        i++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==flag)
                cout<<i<<' '<<j;
        }
    }
    return 0;
}
