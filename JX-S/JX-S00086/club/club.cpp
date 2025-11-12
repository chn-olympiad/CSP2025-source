#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

typedef pair<int,int> PII;
typedef long long ll;

struct node{
    int val;
    PII ch1,ch2;
    bool operator<(const node &b)const
    { return ch1.first-ch2.first<b.ch1.first-b.ch2.first; }
    bool operator>(const node &b)const
    { return ch1.first-ch2.first>b.ch1.first-b.ch2.first; }
}a[N];

priority_queue<node,vector<node>,greater<node> >q[4];

int n;

void match(int i)
{
    PII ch1=a[i].ch1;
    PII ch2=a[i].ch2;
    int id=ch1.second;
    if(q[id].size()<n/2)
    {
        q[id].push({ch1.first,ch1,ch2});
    }
    else
    {
        node t=q[id].top();
        if(ch1.first-ch2.first>t.ch1.first-t.ch2.first)
        {
            q[id].pop();
            q[id].push({ch1.first,ch1,ch2});
            q[t.ch2.second].push({t.ch2.first,t.ch1,t.ch2});
        }
        else
        {
            q[ch2.second].push({ch2.first,ch1,ch2});
        }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            vector<PII> v(4);
            for(int j=0; j<3; j++)
            {
                cin>>v[j].first;
                v[j].second=j+1;
            }
            sort(v.begin(),v.end(),greater<PII>());
            a[i].ch1=v[0];
            a[i].ch2=v[1];
        }
        
        for(int i=1; i<=n; i++) match(i);

        ll ans=0;

        for(int i=1; i<=3; i++)
            while(!q[i].empty())
            {
                ans+=q[i].top().val;
                q[i].pop();
            }

        cout<<ans<<"\n";
    }

    return 0;
}