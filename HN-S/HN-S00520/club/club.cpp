#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
    return x * f;
}
const int N = 1e5 + 5;
struct node{
    int a, b, c;
}stu[N];
struct del{
    int num, pos, id, orr;
    bool operator <(const del &t) const{
        return num > t.num;
    }
};
del order[N][5];
bool cmp(del x, del y){
    return x.num > y.num;
}
bool cmp2(node x, node y){
    return x.a > y.a;
}
priority_queue <del> q[5];
int maxx = -1, n;
void dfs(int ca, int cb, int cc, int x, int sum){
    if(x > n){
        maxx = max(maxx, sum);
        return ;
    }
    if(ca < n / 2){
        dfs(ca + 1, cb, cc, x + 1, sum + stu[x].a);
    }
    if(cb < n / 2){
        dfs(ca, cb + 1, cc, x + 1, sum + stu[x].b);
    }
    if(cc < n / 2){
        dfs(ca, cb, cc + 1, x + 1, sum + stu[x].c);
    }
    return ;
}
void solve1(){
    maxx = -1;
    dfs(0, 0, 0, 1, 0);
    printf("%lld\n", maxx);
    return ;
}
void solve2(){
    for(int i = 1; i <= n; i++){
        if(q[order[i][1].pos].size() < n / 2){
            q[order[i][1].pos].push(order[i][1]);
        }else{
            del tmp = q[order[i][1].pos].top();
            if(order[tmp.id][tmp.orr].num - order[tmp.id][tmp.orr + 1].num < order[i][1].num && 
            order[i][1].num + order[tmp.id][tmp.orr + 1].num > order[tmp.id][tmp.orr].num + order[i][2].num){
                q[order[i][1].pos].pop();
                q[order[tmp.id][tmp.orr + 1].pos].push(order[tmp.id][tmp.orr + 1]);
                q[order[i][1].pos].push(order[i][1]);
            }else{
                q[order[i][2].pos].push(order[i][2]);
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= 3; i++){
        while(!q[i].empty()){
            sum += q[i].top().num;
            q[i].pop();
        }
    }
    printf("%lld\n", sum);
    return ;
}
void solve3(){
    sort(stu + 1, stu + n + 1, cmp2);
    int sum = 0;
    for(int i = 1; i <= n / 2; i++){
        sum += stu[i].a;
    }
    printf("%lld\n", sum);
    return ;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while(T--){
        n = read();
        int flagb = 0, flagc = 0;
        for(int i = 1; i <= n; i++){
            stu[i].a = read(), stu[i].b = read(), stu[i].c = read();
            if(stu[i].b) flagb = 1;
            if(stu[i].c) flagc = 1;
            order[i][1].num = stu[i].a;
            order[i][2].num = stu[i].b;
            order[i][3].num = stu[i].c;
            order[i][1].pos = 1;
            order[i][2].pos = 2;
            order[i][3].pos = 3;
            order[i][1].id = i;
            order[i][2].id = i;
            order[i][3].id = i;
            sort(order[i] + 1, order[i] + 3 + 1, cmp);
            order[i][1].orr = 1;
            order[i][2].orr = 2;
            order[i][3].orr = 3;
        }
        if(n <= 10){
            solve1();
        }else{
            if(!flagb && !flagc){
                solve3();
            }else{
                solve2();
            }
        }
    }
    return 0;
}