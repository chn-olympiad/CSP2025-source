#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+233;
int n,a[N][4];
int cho[N],cnt[4];
ll ANS;
inline void dfs(int k)
{
    if (k==n+1)
    {
        ll sum=0;
        for (int i=1;i<=n;i++)
            sum+=a[i][cho[i]];
        ANS=max(ANS,sum);
        return;
    }
    for (int i=1;i<=3;i++)
    {
        if (cnt[i]<n/2)
        {
            cnt[i]++;
            cho[k]=i;
            dfs(k+1);
            cnt[i]--;
        }
    }
}
inline void forc()
{
    memset(cnt,0,sizeof cnt),ANS=0;
    dfs(1);
    cout<<ANS<<endl;
}
inline bool trA()
{
    for (int i=1;i<=n;i++)
        if (a[i][2]||a[i][3]) return 0;
    return 1;
}
inline bool trB()
{
    for (int i=1;i<=n;i++)
        if (a[i][3]) return 0;
    return 1;
}
inline void doA()
{
    vector<int> v;
    ll s=0;
    for (int i=1;i<=n;i++)
        v.pb(a[i][1]);
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0;i<n/2;i++) s+=v[i];
    cout<<s<<endl;
}
inline void doB()
{
    vector<int> v;
    ll s=0;
    for (int i=1;i<=n;i++)
        s+=a[i][2],v.pb(a[i][1]-a[i][2]);
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0;i<n/2;i++) s+=v[i];
    cout<<s<<endl;
}
multiset<pii> st[4];
inline void _main()
{
    cin>>n;
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=3;j++) cin>>a[i][j];
    if (n<=10) return forc();
    if (trA()) return doA();
    if (trB()) return doB();
    for (int i=1;i<=n;i++)
    {
        int k=1;
        for (int j=2;j<=3;j++)
            if (a[i][j]>a[i][k]) k=j;
        if (st[k].size()<n/2)
            st[k].insert({a[i][k],i});
        else
        {
            int mx=0;
            for (int j=1;j<=3;j++)
                if (j!=k) mx=max(mx,a[i][j]);
            int t=st[k].begin()->second;
            int Mx=0;
            for (int j=1;j<=3;j++)
                if (j!=k) Mx=max(Mx,a[t][j]);
            if (Mx-st[k].begin()->first+a[i][k]>mx)
            {
                st[k].erase(st[k].begin());
                for (int j=1;j<=3;j++)
                    if (j!=k&&Mx==a[t][j])
                    {
                        st[j].insert({a[t][j],t});
                        break;
                    }
                st[k].insert({a[i][k],i});
            }
            else
            {
                for (int j=1;j<=3;j++)
                    if (j!=k&&mx==a[i][j])
                    {
                        st[j].insert({a[i][j],i});
                        break;
                    }
            }
        }
    }
    for (int j=1;j<=3;j++)
        while (st[j].size())
            ans+=st[j].begin()->first,st[j].erase(st[j].begin());
    cout<<ans<<endl;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int t; cin>>t;
    while (t--)_main();

    return 0;
}


