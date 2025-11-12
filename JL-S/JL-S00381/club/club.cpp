#include<bits/stdc++.h>
using namespace std;
    int sum[200005][3];
    int n;
    int cnt[3];
    int coun=0;
    int maxn=0;
    int ans=0;
void dfs(int j)
{
    for(int i=0;i<3;i++)
    {
        if(cnt[i]>n/2)
            return;
    }
    if(j==n)
    {
        ans=max(ans,coun);
        return;
    }

    for(int i=0;i<3;i++)
    {
        coun+=sum[j][i];
        cnt[i]++;
        j++;
        dfs(j);
        j--;
        cnt[i]--;
        coun-=sum[j][i];
    }
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);

    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>sum[i][0];
            cin>>sum[i][1];
            cin>>sum[i][2];
        }
        dfs(0);
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
