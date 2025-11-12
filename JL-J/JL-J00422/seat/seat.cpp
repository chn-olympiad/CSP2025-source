#include<bits/stdc++.h>
using namespace std;
int n,m;
int temp;
int q;
int a[20][20];
int b[400];
int flag[20][20];
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int x,int y,int k)
{
    if(b[k]==q)
    {
        cout<<x<<" "<<y;
    }
    a[x][y]=b[k];
    flag[x][y]=1;
    if(flag[x][y+1]==0&&y+1<=n) dfs(x,y+1,k+1);
    if(flag[x][y-1]==0&&y-1>=1) dfs(x,y-1,k+1);
    if(flag[x+1][y]==0&&x+1<=m) dfs(x+1,y,k+1);
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    temp=n*m;
    for(int i=1;i<=temp;i++) cin>>b[i];
    q=b[1];
    sort(b+1,b+temp+1,cmp);
    dfs(1,1,1);
    return 0;
}
