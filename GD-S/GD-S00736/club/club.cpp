#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 1e5 + 10;

int t, n, res;
int a[maxn], b[maxn], c[maxn];

struct Val{
    int pos;
    constexpr Val(int pos = 0): pos(pos){}
    inline bool operator < (const Val & other) const {
        return max({a[pos], b[pos], c[pos]}) < max({a[other.pos], b[other.pos], c[other.pos]});
    }
};

struct Modi{
    int pos, o;
    constexpr Modi(int pos = 0, int o = 0): pos(pos), o(o){}
    inline pair<int, int> getval(){
        return !o ? make_pair(b[pos] - a[pos], c[pos] - a[pos]) : o == 1 ? make_pair(a[pos] - b[pos], c[pos] - b[pos]) : make_pair(a[pos] - c[pos], b[pos] - c[pos]);
    }
    inline bool operator < (const Modi & other) const {
        return !o ? max(b[pos] - a[pos], c[pos] - a[pos]) < max(b[other.pos] - a[other.pos], c[other.pos] - a[other.pos]) : o == 1 ? max(a[pos] - b[pos], c[pos] - b[pos]) < max(a[other.pos] - b[other.pos], c[other.pos] - b[other.pos]) : max(a[pos] - c[pos], b[pos] - c[pos]) < max(a[other.pos] - c[other.pos], b[other.pos] - c[other.pos]);
    }
};
priority_queue<Val> q;
priority_queue<Modi> modi[3];

inline bool calc(int now, int o){
    if (modi[o].size() < n >> 1){
        modi[o].push(Modi(now, o)), res += (!o ? a : o == 1 ? b : c)[now];
        return true;
    }
    Modi v = modi[o].top();
    const pair<int, int> tmp = v.getval();
    if (max(tmp.first, tmp.second) > (!o ? max(b[now] - a[now], c[now] - a[now]) : o == 1 ? max(a[now] - b[now], c[now] - b[now]) : max(a[now] - c[now], b[now] - c[now]))){
        modi[o].pop(), modi[o].push(Modi(now, o)), res += (!o ? a : o == 1 ? b : c)[now] + max(tmp.first, tmp.second), tmp.first > tmp.second ? modi[!o ? 1 : 0].push(Modi(v.pos, !o ? 1 : 0)) : modi[o == 2 ? 1 : 2].push(Modi(v.pos, o == 2 ? 1 : 2));
        return true;
    }
    return false;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n), res = 0;
        for (int i = 0; i < 3; i++){
            for (;!modi[i].empty(); modi[i].pop());
        }
        for (int i = 1; i <= n; i++){
            scanf("%d %d %d", &a[i], &b[i], &c[i]), q.push(Val(i));
        }
        while (!q.empty()){
            const int now = q.top().pos;
            q.pop();
            pair<int, int> tmp[3] = {{a[now], 0}, {b[now], 1}, {c[now], 2}};
            sort(tmp, tmp + 3, greater<>());
            for (int i = 0; i < 3; i++){
                if (calc(now, tmp[i].second)){
                    break;
                }
            }
        }
        printf("%d\n", res);
    }

return 0;
}