#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][4],ans,cnt1,cnt2,cnt3;
bool mark[100005];
vector<int>v1,v2,v3;
struct dt
{
    ll num,id,ind;
};
bool operator < (dt x,dt y)
{
    return x.num>y.num;
}
priority_queue<dt>q;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        ans=0;
        while(!q.empty())
            q.pop();
        v1.clear();
        v2.clear();
        v3.clear();
        cin>>n;
        for(int i=0;i<=n;i++)
            mark[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            ll maxx=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]==maxx)
                v1.push_back(i);
            else if(a[i][2]==maxx)
                v2.push_back(i);
            else
                v3.push_back(i);
            ans+=maxx;
        }
        cnt1=v1.size(),cnt2=v2.size(),cnt3=v3.size();
        if(v1.size()>n/2)
        {
            for(int i=0;i<v1.size();i++)
            {
                q.push({a[v1[i]][1]-a[v1[i]][2],2,i});
                q.push({a[v1[i]][1]-a[v1[i]][3],3,i});
            }
            while(cnt1>n/2&&!q.empty())
            {
                dt x=q.top();
                q.pop();
                if(x.id==2&&cnt2<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt1--;
                    cnt2++;
                    mark[x.ind]=1;
                }
                if(x.id==3&&cnt3<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt1--;
                    cnt3++;
                    mark[x.ind]=1;
                }
            }
        }
        if(v2.size()>n/2)
        {
            for(int i=0;i<v2.size();i++)
            {
                q.push({a[v2[i]][2]-a[v2[i]][1],1,i});
                q.push({a[v2[i]][2]-a[v2[i]][3],3,i});
            }
            while(cnt2>n/2&&!q.empty())
            {
                dt x=q.top();
                q.pop();
                if(x.id==1&&cnt1<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt2--;
                    cnt1++;
                    mark[x.ind]=1;
                }
                if(x.id==3&&cnt3<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt2--;
                    cnt3++;
                    mark[x.ind]=1;
                }
            }
        }
        if(v3.size()>n/2)
        {
            for(int i=0;i<v3.size();i++)
            {
                q.push({a[v3[i]][3]-a[v3[i]][2],2,i});
                q.push({a[v3[i]][3]-a[v3[i]][1],1,i});
            }
            while(cnt3>n/2&&!q.empty())
            {
                dt x=q.top();
                q.pop();
                if(x.id==2&&cnt2<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt3--;
                    cnt2++;
                    mark[x.ind]=1;
                }
                if(x.id==1&&cnt1<n/2&&!mark[x.ind])
                {
                    ans-=x.num;
                    cnt3--;
                    cnt1++;
                    mark[x.ind]=1;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
