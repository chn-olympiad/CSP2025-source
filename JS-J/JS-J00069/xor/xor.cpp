#include <bits/stdc++.h>
using namespace std;
const long long maxn=5e5;
long long cspt=0,cspa[maxn],cspk,cspn;
bool cspb[maxn];

void dfs(long long l,long long r)
{
    for(int i=l;i<=r;i++)
    {
        if(cspa[i]==cspk)
        {
            cspt++;
            cspb[i]=true;
            dfs(l,i-1);
            dfs(i+1,r);
        }
    }
    if(l>r||l<1||r>cspn) return;
    for(int i=l,foot=1;i<=r;i++,foot++)
    {
        int ans=cspa[i];
        for(int j=i+1;j<=i+foot;j++)
        {
            ans=ans^cspa[j];
        }
        if(ans==cspk)
        {
            cspt++;
            for(int j=i;j<=i+foot;j++)
            {
                cspb[j]=true;
            }
            dfs(l,i-1);
            dfs(i+foot+1,r);
            break;
        }
    }
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&cspn,&cspk);
    for(int i=1;i<=cspn;i++)
    {
        scanf("%lld",&cspa[i]);
        cspb[i]=false;
    }
    long long l=1,r=cspn;
    dfs(l,r);
    printf("%lld",cspt);
    return 0;
}
