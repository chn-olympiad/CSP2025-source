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
    int n,m,ans;
    cin>>n>>m;
    int x=n*m;
    int a[1145];
    for(int i=1;i<=x;i++)cin>>a[i];
    ans=a[1];
    sort(a+1,a+x+1,cmp);
    int c,r;
    int s[20][20];
    int k=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++,k++)s[i][j]=a[k];
        }
        else{
            for(int j=n;j>=1;j--,k++)s[i][j]=a[k];
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(s[i][j]==ans)
        {
            c=i;
            r=j;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
