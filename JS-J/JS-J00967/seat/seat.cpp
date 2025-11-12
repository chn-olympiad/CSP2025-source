#include<bits/stdc++.h>
using namespace std;
const int N=1234;
int n,m,k;
int a[N];
void dfs(int dep,int x,int y,int s,int u)
{
    //cout<<dep<<" "<<x<<" "<<y<<" "<<s<<endl;
    if(a[dep]==k)
    {
        cout<<x<<" "<<y;
        exit(0);
    }
    if(s!=4)
    {
        dfs(dep+1,x,y+u,s+1,u);
    }
    else if(s==4)
    {
        dfs(dep+1,x+1,y,1,-u);
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    a[1]=k;
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    dfs(1,1,1,1,1);
    return 0;
}
