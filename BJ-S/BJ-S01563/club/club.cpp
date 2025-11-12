/*

#include <bits/stdc++.h>
#include <queue>

typedef long long ll;

using std::cin;
using std::cout;

struct data{
    ll a,b,c;
};

struct heap{
    ll w, a, b, c;

    bool operator <(const heap &o)const {
        return w>o.w;
    }
};

std::queue<data> que;
std::priority_queue<heap> q[3];
std::priority_queue<heap> f;
ll t, n;

void solve() {
    while(q[0].size()) {
        q[0].pop();
    }
    while(q[1].size()) {
        q[1].pop();
    }
    while(q[2].size()) {
        q[2].pop();
    }


    cin>>n;
    ll res=0;
    for(ll i=1;i<=n;++i) {
        ll a,b,c;
        cin>>a>>b>>c;
        que.push({a,b,c});
    }

    while(!que.empty()) {
        ll a,b,c;
        a=que.front().a;
        b=que.front().b;
        c=que.front().c;
        que.pop();
        std::pair<ll, ll> arr[3];
        if(q[0].size() >= (n>>1)) {
            arr[0].first = a-q[0].top().w;
        }else{
            arr[0].first=a;
        }
        arr[0].second = 0;
        if(q[1].size() >= (n>>1)) {
            arr[1].first = b-q[1].top().w;
        }else{
            arr[1].first=b;
        }
        arr[1].second = 1;
        if(q[2].size() >= (n>>2)) {
            arr[2].first = c-q[2].top().w;
        }else{
            arr[2].first=c;
        }
        arr[2].second = 2;
        std::sort(arr,arr+3);
        std::pair<ll,ll> temp=arr[2];
        if(q[temp.second].size() >= (n>>1)) {
            heap t=q[temp.second].top();
            res+=temp.first;
            q[temp.second].push({(ll)temp.first+t.w,a,b,c});
            q[temp.second].pop();
            que.push({t.a, t.b, t.c});
        }else{
            res+=temp.first;
            q[temp.second].push({temp.first, a, b, c});
        }
    }
    printf("%lld\n", res);
}

int main() {
    freopen("input", "r", stdin);
    cin>>t;
    while(t--) {
        solve();
    }
	return 0;
}

*/

#include <bits/stdc++.h>

typedef long long int ll;

using std::cin;

const ll maxn = 205;

struct data{
    ll a,b,c;
};

ll dp[maxn][maxn][maxn];
data a[maxn];
ll n, t;

void subtask() {
    std::sort(a+1,a+1+n, [](const data &a, const data &b) {
        return a.a-a.b > b.a-b.b;
    });
    ll ans=0;
    for(ll i=1;i<=(n>>1);++i) {
        ans+=a[i].a;
    }
    for(ll i=n;i>(n>>1);i--) {
        ans-=a[i].a;
        ans+=a[i].b;
    }
    printf("%lld\n", ans);
    return;
}

void solve() {
    ll ans=0;
    cin>>n;
    bool flag=false;
    for(ll i=1;i<=n;++i) {
        cin>>a[i].a>>a[i].b>>a[i].c;
        flag|=a[i].c;
    }
    if(!flag) {
        subtask();
        return;
    }
    memset(dp, 0, sizeof dp);
    for(ll i=0;i<=(n>>1);++i) {
        for(ll j=0;j<=(n>>1);++j) {
            for(ll k=0;k<=(n>>1);++k) {
                ll sum=i+k+j;
                if(sum==n) {
                    ans=std::max(ans, dp[i][j][k]);
                    break;
                }
                if(i < (n>>1)) {
                    dp[i+1][j][k] = std::max(dp[i][j][k]+a[sum+1].a, dp[i+1][j][k]);
                }
                if(j < (n>>1)) {
                    dp[i][j+1][k] = std::max(dp[i][j][k]+a[sum+1].b, dp[i][j+1][k]);
                }
                if(k < (n>>1)) {
                    dp[i][j][k+1] = std::max(dp[i][j][k]+a[sum+1].c, dp[i][j][k+1]);
                }
                //puts("");
            }
        }
    }
    printf("%lld\n", ans);
    return;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
