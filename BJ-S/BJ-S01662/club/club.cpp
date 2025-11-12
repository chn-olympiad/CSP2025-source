#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int T,n;
int a[100005][4],chs[100005][4];
priority_queue<pii> q[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
            {
                chs[i][1]=1;chs[i][2]=2;chs[i][3]=3;
            }
            else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
            {
                chs[i][1]=2;chs[i][2]=1;chs[i][3]=3;
            }
            else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
            {
                chs[i][1]=1;chs[i][2]=3;chs[i][3]=2;
            }
            else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
            {
                chs[i][1]=2;chs[i][2]=3;chs[i][3]=1;
            }
            else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
            {
                chs[i][1]=3;chs[i][2]=2;chs[i][3]=1;
            }
            else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
            {
                chs[i][1]=3;chs[i][2]=1;chs[i][3]=2;
            }
            else cout<<"WRONG!\n";
        }
        while(!q[1].empty()) q[1].pop();
        while(!q[2].empty()) q[2].pop();
        while(!q[3].empty()) q[3].pop();
        int lim=n/2;
        for(int i=1;i<=n;i++)
        {
            int ps=chs[i][1];
            if(q[ps].size()>=lim)
            {
                auto d1=q[ps].top();
                if(d1.fi>a[i][chs[i][2]]-a[i][ps])
                {
                    q[ps].pop();
                    ans+=d1.fi;
                    q[chs[d1.se][2]].push({-2e9,d1.se});
                    ans+=a[i][ps];
                    q[ps].push({a[i][chs[i][2]]-a[i][ps],i});
                }
                else
                {
                    ans+=a[i][chs[i][2]];
                    q[chs[i][2]].push({-2e9,i});
                }
            }
            else
            {
                ans+=a[i][ps];
                q[ps].push({a[i][chs[i][2]]-a[i][ps],i});
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}




