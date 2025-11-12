#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct edge{
    int x , y;
    long long prime;
    void read(){
        scanf("%d%d%lld" , &x , &y , &prime);
    }
    bool operator < (const edge& a)const{
        return prime < a.prime;
    }
};
vector<int> t[20];
vector<edge> e;
int f[10010];
long long c[20];
int cnt;
long long ans = 1e18;
bool flg = true;
int n , m , k;
void input(){
    scanf("%d%d%d" , &n , &m , &k);
    for(int i = 1 ; i <= m ; i++){
        edge t;
        t.read();
        e.push_back(t);
    }
    cnt = m;
    for(int i = 1 ; i <= k ; i++){
        scanf("%lld" , &c[i]);
        if(c[i] != 0) flg = false;
        for(int j = 1 ; j <= n ; j++){
            long long T;
            scanf("%lld" , &T);
            if(T != 0) flg = false;
            t[i].push_back(T);
        }
    }
    if(flg){
        printf("0");
        exit(0);
    }
}
void init(int n){
    for(int i = 1 ; i <= n ; i++) f[i] = i;
}
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
long long kru(int n , vector<edge> e){
    int m = e.size();
    sort(e.begin() , e.end());
    init(n);
    long long ans = 0;
    int cnt = 0;
    for(auto k : e){
        if(cnt >= n - 1) return ans;
        long long t = k.prime;
        int x = k.x;
        int y = k.y;
        x = find(x);
        y = find(y);
        if(x != y){
            ans += t;
            cnt++;
            f[x] = y;
        }
    }
    return 1e18;
}
void dfs(int i , int cnt , long long tot){
    if(tot >= ans) return;
    if(i > k){
        ans = min(ans , kru(n + cnt , e) + tot);
        return;
    }
    dfs(i + 1 , cnt , tot);
    for(int j = 0 ; j < t[i].size() ; j++)
        e.push_back((edge){n + i , j + 1 , t[i][j]});
    dfs(i + 1 , cnt + 1 , tot + c[i]);
    for(int j = 0 ; j < t[i].size() ; j++) e.pop_back();
}
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    input();
    dfs(1 , 0 , 0);
    printf("%lld" , ans);
    return 0;
}
