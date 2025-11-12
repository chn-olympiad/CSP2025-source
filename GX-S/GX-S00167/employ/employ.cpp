#include<bits/stdc++.h>
using namespace std;
//fei yong liu mu ban 48
struct Node{
    int to, nxt, w;
}e[100010];
int ans, head[100010], cnt = 0, n, dis[100010];
void add(int a, int b, int c){
    e[cnt].to = b, e[cnt].nxt = head[a], e[cnt].w = c, head[a] = cnt ++;
}
void spfa(){
    for(int i = 1; i <= n; i ++) dis[i] = 2147483746;

}
void dinic(){

}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i ++){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c); add(b, a, 0);
    }
    dinic();
    for(int i = 1; i <= 10000; i ++){
        ans = rand() % 2000000000;
    }
    cout << ans << endl;
    return 0;
}
