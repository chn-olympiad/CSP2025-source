#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,c,r,s,s1=1;
cin>>n>>m;
int a[n+1][m+1],x[n*m+1];
for(int i=1;i<=n*m;i++)
    cin>>x[i];
s=x[1];
for(int i=1;i<=n*m-1;i++)
    for(int j=1;j<=n*m-i;j++)
        if(x[j]<x[j+1])
            swap(x[j],x[j+1]);
for(int i=1;i<=n;i++)
{
    if(i%2==1)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=x[s1];
            if(a[i][j]==s)
            {
                cout<<i<<" "<<j;
                return 0;
            }
            s1++;
        }
    }
    if(i%2==0)
    {
        for(int j=m;j>=1;j--)
        {
            a[i][j]=x[s1];
            if(a[i][j]==s)
            {
                cout<<i<<" "<<j;
                return 0;
            }
            s1++;
        }
    }
}
fclose(stdin);fclose(stdout);
return 0;
}
