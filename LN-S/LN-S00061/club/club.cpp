#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<pair<double,int>,int> >q;
int t,n,ans,a,b,stu[4];
double lik[500010][4],per;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        bool vis[500010]={0};
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x=0;
            for(int j=1;j<=3;j++)
            {
                cin>>lik[i][j];
                x+=lik[i][j];
            }
            for(int j=1;j<=3;j++)
            {
                q.push({{lik[i][j]/x,j},i});
            }
        }
        for(int i=1;i<=3;i++)stu[i]=0;
        while(!q.empty())
        {
            per=q.top().first.first;a=q.top().first.second;b=q.top().second;
            q.pop();
            if(vis[b]||stu[a]==n/2)continue;
            vis[b]=1;
            stu[a]++;
            ans+=lik[b][a];
        }
        cout<<ans<<endl;
    }
}
