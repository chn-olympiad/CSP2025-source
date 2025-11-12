#include<bits/stdc++.h>
using namespace std;
string s,s1;
bool cmp(int x,int y)
{
    return x>y;
}
int main(void)
{
    long long n,m,c=0,id=0;
    cin>>n>>m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=n*m;i++)cin>>a[i];
    c=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)if(a[i]==c)id=i;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)if(a[i*n+j]==c&&n-j!=0)cout<<i<<" "<<n-j;
        }
        else
        {
            for(int j=n;j>0;j--)if(a[i*n-j+1]==c&&i*n-j+1==id)cout<<i<<" "<<j;
        }
    }
    return 0;
}
