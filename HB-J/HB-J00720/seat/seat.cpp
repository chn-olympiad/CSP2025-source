#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],r,ans1,ans2;
int flag=0;
bool cmp(int n1,int n2)
{
    return n1>n2;
}
void dfs(int i,int j,int k)
{
    if(b[k]==r)
    {
        cout<<i<<" "<<j;
        return;
    }
    a[i][j]=b[k];
    if(flag==0&&j+1>n)
    {
        flag=1;
        dfs(i+1,j,k+1);
        return;
    }
    if(flag==0&&j+1<=n)
    {
        dfs(i,j+1,k+1);
        return;
    }
    if(flag==1)
    {
        flag=2;
        dfs(i,j-1,k+1);
        return;
    }
    if(flag==2&&j-1>=1)
    {
        dfs(i,j-1,k+1);
        return;
    }
    if(flag==2&&j-1<1)
    {
        flag=3;
        dfs(i+1,j,k+1);
        return;
    }
    if(flag==3)
    {
        flag=0;
        dfs(i,j+1,k+1);
        return;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    r=b[1];
    sort(b+1,b+n*m+1,cmp);
    dfs(1,1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
