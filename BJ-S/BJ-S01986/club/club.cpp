#include<bits/stdc++.h>

using namespace std;

constexpr int N=1e5+5;

pair<int, int> a[N][3];
vector<int> v[3];

int T;
int n;
int ans=0;
int c[N];

bool cmp_(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first>p2.first;
}

bool cmp(int x, int y)
{
    return c[x]<c[y];
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>T;
    while(T--)
    {
        /// init
        ans=0;
        v[0].clear();v[1].clear();v[2].clear();
        /// read
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=2;j++)
            {
                cin>>a[i][j].first;a[i][j].second=j;
            }
        /// sort by number
        for(int i=1;i<=n;i++) sort(a[i], a[i]+3, cmp_);
        for(int i=1;i<=n;i++) c[i]=a[i][0].first-a[i][1].first;
        /// find the max element and push it into the vector and count the answer
        for(int i=1;i<=n;i++)
        {
            v[a[i][0].second].push_back(i);ans+=a[i][0].first;
        }
        /// find the group which has more than n/2 peoples
        int cur=-1;
        for(int i=0;i<=2;i++)
            if(v[i].size()*2>n)
            {
                cur=i;break;
            }
        /// if there is no group more than n/2 peoples
        if(cur==-1)
        {
            cout<<ans<<'\n';continue;
        }
        /// sort by cmp
        sort(v[cur].begin(), v[cur].end(), cmp);
        /// get the min kth num by cmp
        for(int i=0;i<(v[cur].size()-(n/2));i++) ans-=c[v[cur][i]];
        /// output the answer
        cout<<ans<<'\n';
    }

    return 0;
}
