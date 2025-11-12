#include<bits/stdc++.h>
using namespace std;

int t, n, biggest = 0, num = 0;
bool flag = false;

struct people {
    int a1, a2, a3;
} a[100005];

void DFS(int pos, int sum, int f, int s, int t) {
    if(pos > n) {
        biggest = max(biggest, sum);
        return;
    }
    if(f + 1 <= num) DFS(pos + 1, sum + a[pos].a1, f + 1, s, t);
    if(s + 1 <= num) DFS(pos + 1, sum + a[pos].a2, f, s + 1, t);
    if(t + 1 <= num) DFS(pos + 1, sum + a[pos].a3, f, s, t + 1);
    return;
}

bool comp(people a, people b) {
    return a.a1 > b.a1;
}

int main() {
    (void)freopen("club.in", "r", stdin);
    (void)freopen("club.out", "w", stdout);
    (void)scanf("%d", &t);
    while(t--) {
        (void)scanf("%d", &n);
        flag = false;
        for(int i = 1; i <= n; i++) {
            (void)scanf("%d %d %d", &a[i].a1, &a[i].a2, &a[i].a3);
            if(a[i].a3 == 0) {
                if(a[i].a2 == 0) {
                    flag = true;
                }
            }
        }
        if(flag) {
            sort(a + 1, a + 1 + n, comp);
            n /= 2;
            int sum = 0;
            for(int i = 1; i <= n; i++) {
                sum += a[i].a1;
            }
            (void)printf("%d\n", sum);
            return 0;
        }
        biggest = 0;
        num = (n / 2);
        DFS(1, 0, 0, 0, 0);
        (void)printf("%d\n", biggest);
    }
    return 0;
}

