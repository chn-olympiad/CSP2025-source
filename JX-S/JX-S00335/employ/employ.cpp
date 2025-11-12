#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
string s;
int c[1000000],b[1000000],a[1000000];
void dfs(int x)
{
    if(x==s.size()+1) sum++;
    for(int i=1;i<=s.size();i++)
    {
        if(b[i]==0)
        {
            a[x]=s[i];
            b[i]=1;
            dfs(x+1);
            b[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m==n) cout<<n;
    else
    {
        dfs(1);
    }
    cout<<sum;
    return 0;
}
