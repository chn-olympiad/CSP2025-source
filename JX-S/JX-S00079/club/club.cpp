#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
};
vector<node>v;
bool cmp1(node x,node y)
{
    return x.a>y.a;
}
int acnt,bcnt,ccnt;
int ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        acnt=bcnt=ccnt=0;ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v.push_back({a,b,c});
        }
        sort(v.begin(),v.end(),cmp1);
        for(auto[a,b,c]:v)
        {
            if(a>=b&&a>=c)
            {
                if(acnt<=n/2)
                {
                    acnt++;
                    ans+=a;
                }
                else
                {
                    if(b>=c&&bcnt<=n/2)
                    {
                        bcnt++;
                        ans+=b;
                    }
                    else ccnt++,ans+=c;
                }
            }
            else if(b>=a&&b>=c)
            {
                if(bcnt<=n/2)
                {
                    bcnt++;
                    ans+=b;
                }
                else
                {
                    if(a>=c&&acnt<=n/2)
                    {
                        acnt++;
                        ans+=a;
                    }
                    else ccnt++,ans+=c;
                }
            }
            else if(c>=a&&c>=b)
            {
                if(ccnt<=n/2)
                {
                    ccnt++;
                    ans+=c;
                }
                else
                {
                    if(a>=b&&acnt<=n/2)
                    {
                        acnt++;
                        ans+=a;
                    }
                    else acnt++,ans+=b;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
