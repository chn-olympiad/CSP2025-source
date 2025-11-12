#include<bits/stdc++.h>
using namespace std;
int n,t,f[6] [111] [111] [111];
struct A
{
    int x,y,z;
}a[100011];
int dfs(int x,int y,int z)
{
    int i=x+y+z;
    if(i>n)
    {
        return 0;
    }
    if(f[t] [x] [y] [z]==0)
    {
        int mx=-(1<<31);
        if(x+1<=n/2)
        {
            mx=max(mx,dfs(x+1,y,z)+a[i].x);
        }
        if(y+1<=n/2)
        {
            mx=max(mx,dfs(x,y+1,z)+a[i].y);
        }
        if(z+1<=n/2)
        {
            mx=max(mx,dfs(x,y,z+1)+a[i].z);
        }
        f[t] [x] [y] [z]=mx;
    }
    return f[t] [x] [y] [z];
}
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        cout<<dfs(0,0,0)<<endl;
    }
    return 0;
}
