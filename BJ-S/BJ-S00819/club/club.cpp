#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100010][5],mx[100010],d[100010],ch[100010],cnt[5],ans;
priority_queue<int,vector<int>,greater<int> >q[5];

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        for(int i=1;i<=n;i++)
            mx[i]=0,ch[i]=1e9;
        for(int i=1;i<=3;i++)
        {
            cnt[i]=0;
            while(!q[i].empty())
                q[i].pop();
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]>mx[i])
                {
                    mx[i]=a[i][j];
                    d[i]=j;
                }
            }
            for(int j=1;j<=3;j++)
            {
                if(j!=d[i])
                    ch[i]=min(ch[i],a[i][d[i]]-a[i][j]);
            }
            cnt[d[i]]++;
            ans+=a[i][d[i]];
            q[d[i]].push(ch[i]);
        }
        for(int i=1;i<=3;i++)
        {
            while(cnt[i]>n/2)
            {
                cnt[i]--;
                ans-=q[i].top();
                q[i].pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}