#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[5005]={0},ans;
void dfs(int x,long long sum,long long maxx)
{
    sum+=x;
    long long sss=0;
    sss=maxx;
    maxx=max(a[x],maxx);
    if(x==n&&maxx*2<sum)
    {
        ans++;
       return ;
    }
    dfs(x+1,sum,maxx);
    dfs(x+1,sum-x,sss);
    return ;
}
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("poligon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
