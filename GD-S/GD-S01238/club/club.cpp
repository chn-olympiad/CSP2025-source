#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 1e5+7;
ll n,a[maxn][4],numclub[3+1],smallans=0;
bool viss[maxn];

#define printf

static inline void dfs(ll nn,ll nans){
    if(nn>n){
        smallans=max(smallans,nans);
        return;
    }

    for(ll i=1;i<=3;i++){
        if(numclub[i]>=n/2)continue;
        numclub[i]++;
        dfs(nn+1,nans+a[nn][i]);
        numclub[i]--;
    }
}

static inline void solvesmall(){
    smallans=0;
    numclub[0]=numclub[1]=numclub[2]=numclub[3]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,0);
    cout<<smallans<<"\n";
}

static inline void solve(){
    ll ans=0;
    cin>>n;
    if(n<=11){
        solvesmall();
        return;
    }
    numclub[0]=numclub[1]=numclub[2]=0;
    for(ll i=0;i<=n;i++)viss[i]=false;
    struct S{
        ll diff,size,club,i;
        inline bool operator<(const S&other)const{
            if(diff==other.diff)return size>other.size; 
            return diff>other.diff;
        }
    };
    vector<S> s;
    s.reserve(n+1);
    for(ll i=1;i<=n;i++){
        struct Tmp{
            ll size,j;
            inline bool operator<(const Tmp&other)const{
                return size>other.size;
            }
        }tmp[4];
        for(ll j=1;j<=3;j++){
            ll b;
            cin>>b;
            tmp[j]={b,j};
        }
        sort(tmp+1,tmp+1+3);
        for(ll j=1;j<=3;j++){
            s.push_back({tmp[j].size-tmp[2].size,tmp[j].size,tmp[j].j,i});
            // printf("S{diff=%lld, size=%lld, club=%lld, i=%lld}\n",s.back().diff,s.back().size,s.back().club,s.back().i);
        }
    }
    sort(s.begin(),s.end());
    for(ll i=0;i<s.size();i++){
        printf("S{diff=%lld, size=%lld, club=%lld, i=%lld}\n",s[i].diff,s[i].size,s[i].club,s[i].i);
    }
    for(ll i=0;i<s.size();i++){
        if(viss[s[i].i])continue;
        if(numclub[s[i].club]<n/2){
            numclub[s[i].club]++;
            viss[s[i].i]=true;
            ans+=s[i].size;
        }
    }
    cout<<ans<<"\n";
    printf("------\n");
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--)solve();
}