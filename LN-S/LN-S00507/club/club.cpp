#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct peo{
    int a,b,c;
}p[100005];
vector<peo>v1,v2,v3;
vector<pair<int,int>>a2,a3;
int n;
int ans;
int vis[1000005];
int lim1,lim2;
inline void solve(vector<peo>a,int ops)
{
    priority_queue<pair<int,int>>p1,p2;
    for(int i=0;i<a.size();i++)
    {
        if(ops==1)
        {
            p1.push({a[i].b-a[i].a,i});
            p2.push({a[i].c-a[i].a,i});
        }
        else if(ops==2)
        {
            p1.push({a[i].a-a[i].b,i});
            p2.push({a[i].c-a[i].b,i});
        }
        else
        {
            p1.push({a[i].a-a[i].c,i});
            p2.push({a[i].b-a[i].c,i});
        }
    }
    int cnt1=lim1,cnt2=lim2;
    while(cnt1-lim1+cnt2-lim2!=a.size()-n/2)
    {
        while((!p1.empty())&&vis[p1.top().second])
            p1.pop();
        while((!p2.empty())&&vis[p2.top().second])
            p2.pop();
        if((p1.empty()||p2.empty()))return;
        if(!lim1)
        {
            ans+=p2.top().first;
            lim2--;
            vis[p2.top().second]++;
            p2.pop();
        }
        else if(!lim2)
        {
            ans+=p1.top().first;
            lim1--;
            vis[p1.top().second]++;
            p1.pop();
        }
        if((p1.empty()||p2.empty()))return;
        ans+=max(p1.top().first,p2.top().first);
        if(p1.top().first>p2.top().first)
        {
            lim1--;
            vis[p1.top().second]++;
            p1.pop();
        }
        else if(p1.top().first<p2.top().first)
        {
            lim2--;
            vis[p2.top().second]++;
            p2.pop();
        }
        else
        {
            if(lim1>lim2)
            {
                lim1--;
                vis[p1.top().second]++;
                p1.pop();
            }
            else
            {
                lim2--;
                vis[p2.top().second]++;
                p2.pop();
            }
        }
    }
}
int t;
void init()
{
    v2.clear();
    v1.clear();
    v3.clear();
    a2.clear();
    a3.clear();
    for(int i=0;i<100005;i++)
        p[i].a=p[i].b=p[i].c=0;
    lim1=lim2=n=ans=0;
    for(int i=0;i<1000005;i++)
        vis[i]=0;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b>>p[i].c;
            if(p[i].a>=p[i].b&&p[i].a>=p[i].c)
            {
                v1.push_back(p[i]);
                ans+=p[i].a;
            }
            else if(p[i].b>=p[i].a&&p[i].b>=p[i].c)
            {
                v2.push_back(p[i]);
                ans+=p[i].b;
            }
            else if(p[i].c>=p[i].a&&p[i].b<=p[i].c)
            {
                v3.push_back(p[i]);
                ans+=p[i].c;
            }
        }
        lim1=lim2=n/2;
        if(max(max(v1.size(),v2.size()),v3.size())<=n/2)
        {
            cout<<ans<<endl;
            continue;
        }
        if(v1.size()>v2.size()&&v1.size()>v3.size())
        {
            lim1-=v2.size();
            lim2-=v3.size();
            solve(v1,1);

        }
        else if((v1.size()<v2.size()&&v2.size()>v3.size()))
        {
            lim1-=v1.size();
            lim2-=v3.size();
            solve(v2,2);
        }
        else
        {
            lim1-=v1.size();
            lim2-=v2.size();
            solve(v3,3);
        }
        cout<<ans<<endl;
    }
    return 0;
}
