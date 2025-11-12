#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int k,n,a[N],ans[N];
long long cnt;
vector<int>v[N];
void dfs(int x,long long step)
{
    cnt=(cnt<step?step:cnt);
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]+1,step+1);
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==k)
        {
            v[i].push_back(i);
        }
        ans[i]=ans[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((ans[i]^ans[j])==k&&j+1!=i)
            {
                v[j+1].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) dfs(i,0);
    printf("%lld",cnt);
    return 0;
}
