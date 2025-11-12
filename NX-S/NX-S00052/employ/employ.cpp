#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,gs,ans=1e17,book[200100],type[2000100],k,c[20][100100],cs[2000100],tim,book2[1000100],book3[100];
struct T
{
    int to,s,b;
};
vector<T>mp[1000010];
void dfs(int x)
{
    tim++;
    if(tim>100010)
    {
        return;
    }
    if(gs==n)
    {
        ans=min(ans,s);
        return;
    }
    for(int i=0;i<mp[x].size();i++)
    {
        T to=mp[x][i];
        if(book[to.to]==1)
        {
            continue;
        }
        if(book[to.to]==0&&type[to.to]==0)
        {
            gs++;
        }
        if(type[to.to]==1)
        {
            if(book[to.to]==0)
            {
                s+=cs[to.to];
            }
        }
        if(book2[to.b]==0)
        {
            s+=to.s;
        }
        book[to.to]++;
        book2[to.b]++;
        dfs(to.to);
        book[to.to]--;
        book2[to.b]--;
        if(type[to.to]==1)
        {
            if(book[to.to]==0)
            {
                s-=cs[to.to];
            }
        }
        if(book2[to.b]==0)
        {
            s-=to.s;
        }
        if(book[to.to]==0&&type[to.to]==0)
        {
            gs--;
        }
    }
}
signed main()
{
    freopen("emply.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    cout<<n;
}
