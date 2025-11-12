#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,q;
string s;
int c[1000005];
long long cnt;
int p[1000005];
bool f[1000005];
void dfs(int x)
{
    if(x==q+1)
    {
        int ans=0;
        int h=0;
        for(int i=1;i<=q;i++)
        {
            if(s[i]=='0')
            {
                h++;
                continue;
            }
            if(s[i]=='1' && h<c[p[i]])
            {
                ans++;
            }
            else
            {
                h++;
            }
        }
        if(ans>=m)
        {
            cnt++;
        }
        return ;
    }
    for(int i=1;i<=q;i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            p[x]=i;
            dfs(x+1);
            f[i]=0;
        }
    }
    return ;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    q=s.length();
    s=' '+s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    dfs(1);
    cout<<cnt%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
