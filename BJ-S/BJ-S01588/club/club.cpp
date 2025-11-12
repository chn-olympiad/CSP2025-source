#include<bits/stdc++.h>
using namespace std;
int _;
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>_;
    while(_--)
    {
        cin>>n;
        long long ans=0;
        vector<long long>tp[3];
        for(int i=1;i<=n;i++)
        {
            long long a,b,c;
            cin>>a>>b>>c;
            if(a>=b&&a>=c)
            {
                tp[0].push_back(a-max(b,c));
            }
            else if(b>=a&&b>=c)
            {
                tp[1].push_back(b-max(a,c));
            }
            else tp[2].push_back(c-max(a,b));
            ans+=max(c,max(a,b));
        }
        if(tp[0].size()<=n/2&&tp[1].size()<=n/2&&tp[2].size()<=n/2)
        {
            cout<<ans<<'\n';
        }
        else
        {
            for(int i=0;i<3;i++)
            {
                if(tp[i].size()>n/2)
                {
                    sort(tp[i].begin(),tp[i].end(),greater<long long>());
                    while(tp[i].size()>n/2)
                    {
                        ans-=tp[i].back();
                        tp[i].pop_back();
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
}
