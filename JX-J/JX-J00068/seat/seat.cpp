#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,x;
}a[1010];
int b[20][20];
int cnt=0;
int n,m;
void dfs(int x,int y)
{
    cnt++;
    b[x][y]=cnt;
    if(x==n && y==m && m%2==1)
    {
        return ;
    }
    else if(x==1 && y==m && m%2==0)
    {
        return ;
    }
    else if(x==n && y+1<=m && y%2==1)
    {
        dfs(n,y+1);
    }
    else if(x==1 && y+1<=m && y%2==0)
    {
        dfs(1,y+1);
    }
    else if(y%2==1)
    {
        dfs(x+1,y);
    }
    else if(y%2==0)
    {
        dfs(x-1,y);
    }
    return ;
}
bool cmp(node x,node y)
{
    return x.x>y.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int op=-1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            op=i;
        }
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==op)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
