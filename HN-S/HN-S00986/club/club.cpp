#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n;
pair<int,int> a[maxn][4];
bool cmp(pair<int,int> a,pair<int,int> b){return a>b;}
void solve()
{
    cin>>n;
    int cnt[4]={0,0,0,0},sum=0;
    for(int i=1;i<=n;i++)
    {
        a[i][1].second=1;
        a[i][2].second=2;
        a[i][3].second=3;
        cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
        sort(a[i]+1,a[i]+3+1,cmp);
        cnt[a[i][1].second]++,sum+=a[i][1].first;
    }
    if(max({cnt[1],cnt[2],cnt[3]})<=n/2){cout<<sum<<"\n";return ;}
    int opt;
    if(cnt[1]>n/2) opt=1;
    if(cnt[2]>n/2) opt=2;
    if(cnt[3]>n/2) opt=3;
    int tot=max({cnt[1],cnt[2],cnt[3]})-n/2;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
    {
        if(a[i][1].second!=opt) continue;
        pq.push(max(a[i][2].first,a[i][3].first)-a[i][1].first);
    }
    while(tot--) sum+=pq.top(),pq.pop();
    cout<<sum<<"\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
