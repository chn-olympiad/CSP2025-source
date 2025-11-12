#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],a[110][110];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>s[i];
    int x=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int j=1;j<=m;j=j+2)
    {
        for(int i=1;i<=n;i++)
        {
            a[i][j]=s[i+(j-1)*n];
        }
        for(int i=n,p=1;i>=1 && p<=n;i--,p++)
        {
            a[i][j+1]=s[p+j*n];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==x) cout<<j<<" "<<i;
        }
    }
    return 0;
}
