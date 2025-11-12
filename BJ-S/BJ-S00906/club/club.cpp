#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int t,n,a[100001],b[100001],c[100001],maxn,zero,sum;
void dfs(int one,int two,int three,int i,int ans)
{
    if(i==n)
    {
        maxn=max(maxn,ans);
        return;
    }
    if(one+1<=n/2)
    {
        dfs(one+1,two,three,i+1,ans+a[i+1]);
    }
    if(two+1<=n/2)
    {
        dfs(one,two+1,three,i+1,ans+b[i+1]);
    }
    if(three+1<=n/2)
    {
        dfs(one,two,three+1,i+1,ans+c[i+1]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0&&c[i]==0)
            {
                zero++;
            }
        }
        if(zero==n)
        {
            stable_sort(a+1,a+n+1,cmp);
            for(int i=1;i*2<=n;i++)
            {
                sum+=a[i];
            }
            cout<<sum;
            return 0;
        }
        dfs(0,0,0,0,0);
        cout<<maxn;
        maxn=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
