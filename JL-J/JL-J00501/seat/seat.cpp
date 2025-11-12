#include<bits/stdc++.h>
using namespace std;
int n,m,w,z=0;
int a[200];
int b[20][20]={0};
int dfs(int x,int y,int k)
{
    if(z==1)
        return 0;
    if(k==w)
    {
        cout<<y<<" "<<x<<endl;
        z=1;
        return 0;
    }
    b[x][y]=1;
    if(x+1<=n&&y<=m&&b[x+1][y]!=1)
        dfs(x+1,y,k+1);
    if(x-1>=1&&y<=m&&b[x-1][y]!=1)
        dfs(x-1,y,k+1);
    if(x<=n&&y+1<=m&&b[x][y+1]!=1)
        dfs(x,y+1,k+1);
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    w=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++)
        if(a[i]==w)
        {
            w=n*m-i+1;
            break;
        }
    dfs(1,1,1);
    return 0;
}
