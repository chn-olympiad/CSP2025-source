#include<bits/stdc++.h>
using namespace std;
int a[5010];
int num[5010];
int b[5010];
int n,ans;
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int cnt,int death)
{

    if(death>n)
    {

        for(int i=1;i<=cnt;i++)
        {
            b[i]=num[i];
        }
        sort(b+1,b+cnt+1,cmp);
        long long len=0;
        for(int i=1;i<=cnt;i++)
        {
            len+=b[i];
        }
        if(len>b[1]*2&&cnt>=3)
        {
            ans++;
        }
        return ;
    }
    num[cnt+1]=a[death];
    dfs(cnt+1,death+1);
    dfs(cnt,death+1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,1);
    cout<<ans%998244353;
    return 0;
}
