#include<bits/stdc++.h>
using namespace std;
int n,m,len;
int s[20][20],a[410];
void dfs(int x,int y,int z)
{
    if (a[z]!=len)
    {
        if (y%2==1)
        {
            if (x==n)
            {
                dfs(x,y+1,z-1);
            }
            else if (x<=n)
            {
                dfs(x+1,y,z-1);
            }
        }
        else if(y&2==0)
        {
            if (x==1)
            {
                dfs(x,y+1,z-1);
            }
            else if (x>=1)
            {
                dfs(x-1,y,z-1);
            }
        }
    }
    else
    {
        cout<<x<<y;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    a[1]=len;
    sort(a+1,a+n*m+1);
    dfs(1,1,n*m);
    return 0;
}
