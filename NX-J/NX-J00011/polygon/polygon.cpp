#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],res,_max=-1,da[5005][5005],he[5005][5005],c;
const int INS=998244353;
void dfs(int x,int xu,int he,int da)
{
    if(x==c+1)
    {
        if(he>da*2)
        {
            res++;
            res%=INS;
        }
        return ;
    }
    for(int i=xu+1;i<=n;i++)
    {
        dfs(x+1,i,he+a[i],max(da,a[i]));
    }
}
void work()
{
    for(int i=1;i<=n;i++)
    {
        dfs(2,i,a[i],a[i]);
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        _max=max(_max,a[i]);
    }
    if(_max==1)
    {
        cout<<(n-1)*(n-2)/2%INS;
        return 0;
    }
    for(c=3;c<=n;c++)
    {
        work();
    }
    cout<<res%INS;
    return 0;
}
