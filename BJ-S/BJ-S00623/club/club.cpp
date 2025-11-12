#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> pii;
const int N=1e5+10;
int a[N][3];
vector<pii> jc[3];

void Solve()
{
    long long sum=0;
    int n;cin>>n; jc[0].clear(),jc[1].clear(),jc[2].clear();
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++) {
        sum+=max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0]==max(a[i][0],max(a[i][1],a[i][2]))) jc[0].push_back({i,a[i][0]-max(a[i][2],a[i][1])});
        else if(a[i][1]==max(a[i][0],max(a[i][1],a[i][2]))) jc[1].push_back({i,a[i][1]-max(a[i][2],a[i][0])});
        else if(a[i][2]==max(a[i][0],max(a[i][1],a[i][2]))) jc[2].push_back({i,a[i][2]-max(a[i][0],a[i][1])});
    }
    sort(jc[0].begin(),jc[0].end(),[](pii a,pii b){return a.second>b.second;});
    sort(jc[1].begin(),jc[1].end(),[](pii a,pii b){return a.second>b.second;});
    sort(jc[2].begin(),jc[2].end(),[](pii a,pii b){return a.second>b.second;});
    int lim=n/2;
    // for(auto x:jc[1]) cout<<x.second<<' ';
    if(jc[0].size()>(n/2)) {
        for(int i=lim;i<jc[0].size();i++) sum-=jc[0][i].second;
    }
    if(jc[1].size()>(n/2)) {
        for(int i=lim;i<jc[1].size();i++) sum-=jc[1][i].second;
    }
    if(jc[2].size()>(n/2)) {
        for(int i=lim;i<jc[2].size();i++) sum-=jc[2][i].second;
    }cout<<sum<<endl;
    return ;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--) Solve();
    return 0;// qwq
}