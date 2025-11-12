#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
int dfs(int f)
{
    int maxx=0;
    for(int i=f;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]^a[j]==k) maxx=max(maxx,dfs(j+1));
        }
    }
    return maxx+1;
}
int main()
{
    #if 1
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++)//yi huo he
    {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    cout<<dfs(1);
    return 0;
}
