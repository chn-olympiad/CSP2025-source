#include <iostream>
using namespace std;
int a[5001],t[5001],way;int n;long long sum;

void dfs(long long mx,int now,int line,unsigned long long sum)
{
    if(line>=3)
    {
        if(mx*2<sum)
        {
            way++;
            way%=998244353;
        }
    }
    for(int i=now;i<=n;i++)
    {
        if(mx<a[i]) dfs(a[i],i+1,line+1,sum+a[i]);
        if(mx>=a[i]) dfs(mx,i+1,line+1,sum+a[i]);
    }
}

int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        dfs(a[i],i+1,1,a[i]);
    }
    cout<<way;

    return 0;

}
