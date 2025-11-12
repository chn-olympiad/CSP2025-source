#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e5+10;
int T,n;
int pos[maxn],cnt[10];
vector<pair<int,int> >a[maxn];
priority_queue<int,vector<int>,greater<int> >q;
inline void ipt(){
    scanf("%lld",&n);
    for(int i=1;i<=3;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int u;
            scanf("%lld",&u);
            a[i].push_back(make_pair(u,j));
        }
    }
}
inline void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());
        cnt[a[i][0].second]++;
        pos[i]=a[i][0].second;
        ans+=a[i][0].first;
    }
    int s=1;
    for(int i=2;i<=3;i++){
        if(cnt[i]>cnt[s])s=i;
    }
    if(cnt[s]<=n/2){
        printf("%lld\n",ans);
        return ;
    }
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        if(pos[i]==s)q.push(a[i][0].first-a[i][1].first);
    }
    while(cnt[s]>n/2){
        ans-=q.top();
        q.pop();
        --cnt[s];
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        ipt();
        solve();
    }

    return 0;
}