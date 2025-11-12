#include <bits/stdc++.h>
#define llong long long
#define N 100005
using namespace std;

struct Node{
    int a, b, c;
    int sub;
    Node(){}
    Node(int o1, int o2, int o3, int o4){a = o1, b = o2, c = o3, sub = o4;}
    bool operator<(const Node o)const{return sub<o.sub;}
    bool operator>(const Node o)const{return sub>o.sub;}
} a[N];
int cnt[4];
int n, m, pos;
llong ans;

priority_queue<Node> pq;

void init(){
    ans  = 0;
    cnt[1] = cnt[2] = cnt[3] = 0;
    return;
}

int calc(int a, int b, int c){
    int tmp[4] = {0, a, b, c};
    sort(tmp+1, tmp+4);
    return tmp[3]-tmp[2];
}

int _main(){
    scanf("%d", &n), m = n>>1;
    for(int i = 1; i <= n; ++i)
        scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c), a[i].sub = calc(a[i].a, a[i].b, a[i].c);
    for(int i = 1; i <= n; ++i)
        pq.push(a[i]);
    while(pq.size()){
        Node now = pq.top(); pq.pop();
        int a = now.a, b = now.b, c = now.c;
        if(a == -1){
            if(b > c) ans += b, ++cnt[2];
            else      ans += c, ++cnt[3];
        }
        else if(b == -1){
            if(a > c) ans += a, ++cnt[1];
            else      ans += c, ++cnt[3];
        }
        else if(c == -1){
            if(b > a) ans += b, ++cnt[2];
            else      ans += a, ++cnt[1];
        }
        else if(a > b && a > c){
            if(cnt[1] >= m) pq.emplace(-1, b, c, abs(b-c));
            else ans += a, ++cnt[1];
        }
        else if(b > c){
            if(cnt[2] >= m) pq.emplace(a, -1, c, abs(a-c));
            else ans += b, ++cnt[2];
        }
        else{
            if(cnt[3] >= m) pq.emplace(a, b, -1, abs(a-b));
            else ans += c, ++cnt[3];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

int T;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) init(), _main();
    return 0;
}

/*
14:49 发现自己打了一个假的贪心。
15:02 想出 n^2 DP。
15:46 试图按极差排序。
16:11 假掉了。不应该啊。
16:28 大样例过了……（哭）
*/
