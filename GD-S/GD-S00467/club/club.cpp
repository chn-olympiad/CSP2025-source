#include<bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i = l;i <= r;i ++)
#define dep(i,l,r) for(int i = l;i >= r;i --)
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;

int read(){
    int s = 0,w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

int t;
int n;
int a[200010][4];
int cnt[10];
int id[200010];

vector <int> q;

void solve(){
    n = read();
    rep(i,1,n)a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
    int ans = 0;
    mem(cnt,0);
    rep(i,1,n){
        int v = max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0] == v){
            cnt[0] ++;
            ans += a[i][0];
            id[i] = 0;
        }
        else {
            if(a[i][1] == v){
                cnt[1] ++;
                ans += a[i][1];
                id[i] = 1;
            }
            else {
                cnt[2] ++;
                ans += a[i][2];
                id[i] = 2;
            }
        }
    }
    int mx = max(cnt[0],max(cnt[1],cnt[2]));
    int grp = -1;
    if(mx > n / 2){
        if(mx == cnt[0])grp = 0;
        if(mx == cnt[1])grp = 1;
        if(mx == cnt[2])grp = 2;
    }
    if(grp == -1){
        printf("%lld\n",ans);
        return ;
    }
    q.clear();
    rep(i,1,n){
        if(id[i] != grp)continue;
        int p1,p2;
        if(id[i] == 0)p1 = 1,p2 = 2;
        if(id[i] == 1)p1 = 0,p2 = 2;
        if(id[i] == 2)p1 = 0,p2 = 1;
        q.push_back(a[i][id[i]] - max(a[i][p1],a[i][p2]));
    }
    sort(q.begin(),q.end());
    int now = 0;
    while(mx > n / 2){
        mx --;
        ans -= q[now];
        now ++;
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t --)solve();
}
