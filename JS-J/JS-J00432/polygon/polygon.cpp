#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],zho=0;
void dfs(int i,int summ,int maxx,int cnt)
{
    if(i>n)
    {
        if(cnt<3)
        {
            return;
        }
        else
        {
            if(summ>maxx*2)
            {
                zho++;
            }
            return;
        }
    }
    dfs(i+1,summ,maxx,cnt);
    dfs(i+1,summ+a[i],max(maxx,a[i]),cnt+1);
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<zho%998244353;
    return 0;
}
