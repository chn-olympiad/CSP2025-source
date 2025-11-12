#include <iostream>
#include <algorithm>
#include <cstdio>
const int N = 1e5 + 7;
class student {
    public:
        int a;
        int b;
        int c;
};
bool max1(student x) {
    return x.a >= x.b && x.a >= x.c;
}
bool max2(student x) {
    return x.b >= x.a && x.b >= x.c;
}
bool max3(student x) {
    return x.c >= x.a && x.c >= x.b;
}
student a1[N], a2[N], a3[N];
int val[N];
int p1 = 0, p2 = 0, p3 = 0;
int main() {
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        p1 = 0, p2 = 0, p3 = 0;
        for(int i = 1; i <= n; i++) {
            student tmp;
            std::cin >> tmp.a >> tmp.b >> tmp.c;
            if(max1(tmp)) {
                a1[++p1] = tmp;
            }
            else if(max2(tmp)) {
                a2[++p2] = tmp;
            }
            else if(max3(tmp)) {
                a3[++p3] = tmp;
            }
        }
        int ans = 0;
        for(int i = 1; i <= p1; i++) ans += a1[i].a;
        for(int i = 1; i <= p2; i++) ans += a2[i].b;
        for(int i = 1; i <= p3; i++) ans += a3[i].c;
        if(p1 <= n/2 && p2 <= n/2 && p3 <= n/2) {
            std::cout << ans << '\n';
        }
        else {
            if(p1 > n/2) {
                for(int i = 1; i <= p1; i++) {
                    val[i] = a1[i].a - std::max(a1[i].b, a1[i].c);
                }
                std::sort(val + 1, val + 1 + p1);
                for(int i = 1; i <= p1 - n/2; i++) ans -= val[i];
            }
            else if(p2 > n/2) {
                for(int i = 1; i <= p2; i++) {
                    val[i] = a2[i].b - std::max(a2[i].a, a2[i].c);
                }
                std::sort(val + 1, val + 1 + p2);
                for(int i = 1; i <= p2 - n/2; i++) ans -= val[i];
            }
            else if(p3 > n/2) {
                for(int i = 1; i <= p3; i++) {
                    val[i] = a3[i].c - std::max(a3[i].a, a3[i].b);
                }
                std::sort(val + 1, val + 1 + p3);
                for(int i = 1; i <= p3 - n/2; i++) ans -= val[i];
            }
            std::cout << ans << '\n';
        }
    }
    return 0;
}