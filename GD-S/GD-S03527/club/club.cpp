#include<bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;

int read(){
    int f = 1,k = 0;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -f;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        k = (k<<1)+(k<<3)+c-48;
        c = getchar();
    }
    return k*f;
}

struct Node{
    pair<int,int> a[5];
}st[maxn];

int t,n,ans,rt;
int vis[maxn],lst[5];
vector<int> v[5];

bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first == y.first) return x.second < y.second;
    return x.first > y.first;
}

bool cmp1(int x,int y){
    int sum1 = st[x].a[1].first - st[x].a[2].first;
    int sum2 = st[y].a[1].first - st[y].a[2].first;
    return sum1 < sum2;
}

bool check(){
    if(vis[1] > n/2){
        rt = 1;
        return false;
    }
    if(vis[2] > n/2){
        rt = 2;
        return false;
    }
    if(vis[3] > n/2){
        rt = 3;
        return false;
    }
    return true;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t = read();
    while(t--){
        n = read();
        for(int i = 1;i <= n;i++) vis[i] = 0;
        ans = 0;
        for(int i = 1;i <= 3;i++) v[i].clear();
        for(int i = 1;i <= n;i++){
            int x = read(),y = read(),z = read();
            st[i].a[1] = make_pair(x,1);
            st[i].a[2] = make_pair(y,2);
            st[i].a[3] = make_pair(z,3);
            sort(st[i].a + 1,st[i].a + 4,cmp);
        }
        for(int i = 1;i <= n;i++){
            int u = st[i].a[1].second,w = st[i].a[1].first;
            ans += w;
            vis[u]++;
            v[u].push_back(i);
        }

        if(check()){
            cout << ans << endl;
            continue;
        }
        sort(v[rt].begin(),v[rt].end(),cmp1);
        for(int i = 0;i < vis[rt]-(n/2);i++){
            int res = st[v[rt][i]].a[1].first - st[v[rt][i]].a[2].first;
            ans -= res;
        }
        cout << ans << endl;
    }


    return 0;
}
