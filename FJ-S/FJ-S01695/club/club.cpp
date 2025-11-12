#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5; 
int T, n, np, a, b, s, t;
int u[3], p[3], ans;
struct node{int a, b, s, t;}nd[N];
bool cmp(node a, node b){return (a.a - a.b) > (b.a - b.b);}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n), u[0] = u[1] = u[2] = 0, np = n >> 1;
        ans = 0;
        for(int i = 1;i <= n;++i){
            scanf("%d%d%d", &p[0], &p[1], &p[2]);
            a = b = s = t = -1;
            for(int j = 0;j < 3;++j){
                if(a < p[j])b = a, t = s, s = j, a = p[j];
                else if(b < p[j])b = p[j], t = j;
            }
            nd[i] = {a, b, s, t};
        }
        sort(nd + 1, nd + n + 1, cmp);
        for(int i = 1;i <= n;++i){
            if(u[nd[i].s] == np)++u[nd[i].t], ans += nd[i].b;
            else ++u[nd[i].s], ans += nd[i].a;
        }
        printf("%d\n", ans);
    }
    return 0;
}