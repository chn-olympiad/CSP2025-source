#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int s[1005]={0},X;
int n,m;
void dfs(int l,int r,int AT)
{
    if(s[AT]==X)
    {
        printf("%d %d",r,l);
        return;
    }
    if(l==1)
    {
        if(r%2==1)dfs(l+1,r,AT+1);
        else dfs(l,r+1,AT+1);
    }
    else if(l==n)
    {
        if(r%2==1)dfs(l,r+1,AT+1);
        else{
            dfs(l-1,r,AT+1);
        }
    }
    else{
        if(r%2==1)
        {
            dfs(l+1,r,AT+1);
        }
        else dfs(l-1,r,AT+1);
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)
    {
        scanf("%d",&s[i]);
        if(i==0)X=s[i];
    }
    sort(s,s+n*m,cmp);
    dfs(1,1,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
