#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans;
void dfs(int now,int qj,int la)
{
    for(int i=now;i<=n;i++)
    {
        if(i==la)
            continue;
        if(s[i]^s[now-1]==k)
        {
            dfs(i+1,qj+1,now);
        }
    }
    ans=max(ans,qj);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
        s[i]=s[i-1]^a[i];
    }
    dfs(1,0,0);
    cout <<ans;
    return 0;
}
