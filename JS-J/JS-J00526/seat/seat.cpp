#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
int a[15][15];
int b[225];
void f(int x,int y,int s,int k)
{
    if(k>n*m)
    {
        return ;
    }
    a[x][y]=k;
    if(x==n&&s==1)
    {
        f(x,y+1,-1,k+1);
    }
    else if(x==1&&s==-1)
    {
        f(1,y+1,1,k+1);
    }
    else
    {
        f(x+s,y,s,k+1);
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int k;
    cin>>n>>m;
    f(1,1,1,1);
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    k=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(k==b[n*m-a[i][j]+1])
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
