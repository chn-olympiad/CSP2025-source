#include<bits/stdc++.h>
using namespace std;
int a[10000],sum=0,x,f=0;
void dfs(int s,int maxx,int num,int l)
{
    if(s==0)
    {
        if(maxx*2<num)
        {
            sum++;
        }
        sum%=998244353;
        return;
    }
    if(x-l+1<s-1)
    {
        return;
    }
    for(int i=l+1;i<=x;i++)
    {
        dfs(s-1,max(maxx,a[i]),num+a[i],i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        cin>>a[i];
    }
    sort(a,a+x);
    for(int i=3;i<=x;i++)
    {
        dfs(i,0,0,0);
    }
    cout<<sum;
    return 0;
}
