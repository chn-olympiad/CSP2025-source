#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int bl[N];
void run()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    int ans=0;
    int cnt[3]={0};
    for(int i=1;i<=n;i++)
    {
        int k=max({a[i][0],a[i][1],a[i][2]});
        ans+=k;
        if(a[i][0]==k) bl[i]=0;
        else if(a[i][1]==k) bl[i]=1;
        else bl[i]=2;
        cnt[bl[i]]++;
    }
    if(max({cnt[0],cnt[1],cnt[2]})<=n/2)
    {
        cout<<ans<<'\n';
        return ;
    }
    int o;
    if(cnt[0]>n/2) o=0;
    else if(cnt[1]>n/2) o=1;
    else o=2;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++)
    {
        if(bl[i]!=o) continue;
        int k=0;
        for(int j=0;j<3;j++) if(j!=o) k=max(k,a[i][j]);
        q.push(a[i][o]-k);
    }
    while(cnt[o]>n/2)
    {
        ans-=q.top(),q.pop();
        cnt[o]--;
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) run();
    return 0;
}