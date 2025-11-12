#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],ans,cnt[5];
void dfs(int step,int sum)
{
    if(step==n+1)
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(cnt[i]>=(n/2))continue;
        cnt[i]++;
        dfs(step+1,sum+a[i][step]);
        cnt[i]--;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
