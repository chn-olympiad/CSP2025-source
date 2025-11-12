#include<bits/stdc++.h>
using namespace std;
bool cmp (int a,int b)
{
return a>b;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n*m+1]={0},b[n+1][m+1]={0};
for(int i=1;i<=n*m;i++)
{
    cin>>a[i];
}
int c=a[1];

sort(a+1,a+m*n+1,cmp);
int x=1;
for(int i=1;i<=m;i++)
{

    if(i%2!=0)
    {
        for(int j=1;j<=n;j++)
        {

            b[j][i]=a[x];
            x++;

        }
    }
    else
    {
        for(int j=n;j>=1;j--)

        {

            b[j][i]=a[x];
            x++;

        }
    }

}
for(int i=1;i<=n;i++)
{

    for(int j=1;j<=m;j++)
    {
        if(c==b[j][i])
        {

            cout<<i<<" "<<j;
        }
    }

}
return 0;
}
