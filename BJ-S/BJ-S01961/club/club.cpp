#include<bits/stdc++.h>
namespace akioi
{
    using namespace std;
    #define F(i,x,y) for(i=x;i<=y;i++)
    #define rF(i,x,y) for(i=x;i>=y;i--)
    #define int long long
    typedef pair<int,int> PII;
    void cout_better()
    {
        ios::sync_with_stdio(0);
        cout.tie(0),cin.tie(0);
        return;
    }
}
using namespace akioi;
int n,b[200005][4];
PII a[200005][4];
vector<int> v[4];
bool cmp(int x,int y) {return a[x][1].first-a[x][2].first>a[y][1].first-a[y][2].first;}
void check(int x)
{
    if(v[x].size()<=n/2) return;
    sort(v[x].begin(),v[x].end(),cmp);
    int cnt=v[x].size();
    while(cnt>n/2) 
    {
        v[a[v[x].back()][2].second].push_back(v[x].back());
        v[x].pop_back();
        cnt--;
    }
    return;
}
void solve()
{
    cin>>n;
    int i,ans=0;
    F(i,1,n) 
    {
        cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
        a[i][1].second=1,a[i][2].second=2,a[i][3].second=3,b[i][1]=a[i][1].first,b[i][2]=a[i][2].first,b[i][3]=a[i][3].first;
        sort(a[i]+1,a[i]+4,greater<PII>());
        v[a[i][1].second].push_back(i);
    }
    F(i,1,3) check(i);
    F(i,1,3)
    {
        for(auto x:v[i]) ans+=b[x][i];
        v[i].clear();
    }
    cout<<ans<<'\n';
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cout_better();
    int T=1;
    cin>>T;
    while(T--) solve();
}