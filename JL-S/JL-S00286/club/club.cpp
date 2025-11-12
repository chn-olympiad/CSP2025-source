#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
int n,ans;
int tmp[maxn];
int a[maxn],b[maxn],c[maxn];
struct node{
    int x,y,z;
}p[maxn];
void work1(int u){
    if(u == n + 1) {
        int num = 0;
        int aa = 0,bb = 0,cc = 0;
        for(int i = 1 ; i <= n ; i ++){
            if(tmp[i] == 1) num += a[i],++ aa;
            if(tmp[i] == 2) num += b[i],++ bb;
            if(tmp[i] == 3) num += c[i],++ cc;
        }
        if(aa > (n / 2) ) return;
        if(bb > (n / 2)) return;
        if(cc > (n / 2)) return;
        ans = max(ans,num);
        return;
    }
    tmp[u] = 1;
    work1(u + 1);
    tmp[u] = 2;
    work1(u + 1);
    tmp[u] = 3;
    work1(u + 1);
}
bool check_A(){
    int flag = 1;
    for(int i = 1 ; i <= n ; i ++){
        if(b[i] || c[i]) return 0;
    }
    return 1;
}
bool cmp(int x,int y){
    return x > y; 
}
bool cmp2(node x,node y){
    if(x.x == y.x) return x.y > y.y;
    return x.x > y.x; 
}
bool check_B(){
    for(int i = 1 ; i <= n ; i ++) {
        if(c[i]) return 0;
    }
    return 1;
}
void solve(){
    sort(p + 1,p + 1 + n,cmp2);
    int jl = 0;
    for(int i = 1 ; i <= (n / 2) ; i ++) jl += p[i].x;
    for(int i = (n / 2) + 1 ; i <= n ; i ++) jl += p[i].y;
    cout << jl << '\n';
}
void solve2(){
    int yu = 0;
    for(int i = 1; i <= n ; i ++) yu += max(a[i],max(b[i],c[i]));
    cout << yu << '\n';
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T --){
        cin >> n;
        for(int i = 1 ; i <= n ; i ++) cin >> a[i] >> b[i] >> c[i],p[i] = {a[i],b[i],c[i]};
        if(n <= 10){
            work1(1);
            cout << ans << '\n';
        }
        else if (check_A()) {
            sort(a + 1,a + 1 + n,cmp);
            int hj = 0;
            for(int i = 1 ; i <= (n / 2) ; i ++) hj += a[i];
            cout << hj << '\n';
        }
        else if(check_B()){
            solve();
        }
        else{
            solve2();
        }
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/