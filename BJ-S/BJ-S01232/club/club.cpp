// #define DBG

#ifdef DBG
#include <iostream>
#else
#include <fstream>
namespace std {
    ifstream cin("club.in");
    ofstream cout("club.out");
}
#endif
#include <algorithm>
#define let const auto

long long int t, n;
long long int midx;

struct person {
    long long int a[2], pref;
    bool operator<(const person y) const {
        return a[0] - a[1] > y.a[0] - y.a[1];
    }
    #ifdef DBG
    void dbg() {
        std::cerr << "a = [" << a[0] << ", " << a[1] << "], pref = " << pref << ", delta = " << a[1]-a[0] << '\n';
    }
    #endif
} p[163840];

int main() {
    std::cin >> t;
    long long int uti[3], c[3];
    while(t--) {
        std::cin >> n;
        #ifdef DBG
        // std::cout << t << '\n';
        #endif
        let m = n/2;
        c[0] = c[1] = c[2] = 0;
        for(int i = 0; i < n; i++) {
            int m1 = -1, m2 = -1, m1idx = -1, m2idx = -1;
            std::cin >> uti[0] >> uti[1] >> uti[2];
            {
                let j = 0;
                if(uti[j] > m1) {
                    m2 = m1;
                    m1 = uti[j];
                    m2idx = m1idx;
                    m1idx = j;
                } else if(uti[j] > m2) {
                    m2 = uti[j];
                    m2idx = j;
                }
            }
            {
                let j = 1;
                if(uti[j] > m1) {
                    m2 = m1;
                    m1 = uti[j];
                    m2idx = m1idx;
                    m1idx = j;
                } else if(uti[j] > m2) {
                    m2 = uti[j];
                    m2idx = j;
                }
            }
            {
                let j = 2;
                if(uti[j] > m1) {
                    m2 = m1;
                    m1 = uti[j];
                    m2idx = m1idx;
                    m1idx = j;
                } else if(uti[j] > m2) {
                    m2 = uti[j];
                    m2idx = j;
                }
            }
            c[m1idx]++;
            p[i].a[0] = m1;
            p[i].a[1] = m2;
            p[i].pref = m1idx;
            #ifdef DBG
            std::cerr << uti[0] << ' ' << uti[1] << ' ' << uti[2] << ": ";
            p[i].dbg();
            #endif
        }
        midx = 0;
        for(int j = 1; j < 3; j++) {
            if(c[j] > c[midx]) {
                midx = j;
            }
        }
        #ifdef DBG
        std::cerr << "c=[" << c[0] << ',' << c[1] << ',' << c[2] << "], midx = "<< midx << '\n';
        #endif
        long long int ans = 0, cnt = 0;
        std::sort(p, p+n);
        for(int i = 0; i < n; i++) {
            #ifdef DBG
            std::cerr << "ans=" << ans << ", cnt=" << cnt << ": ";
            p[i].dbg();
            #endif
            if(cnt >= m && p[i].pref == midx) {
                ans += p[i].a[1];
                #ifdef DBG
                std::cerr << "Fallback\n";
                #endif
            } else {
                #ifdef DBG
                std::cerr << "Preferred\n";
                #endif
                ans += p[i].a[0];
                if(p[i].pref == midx) {
                    cnt++;
                }
            }
        }
        std::cout << ans << '\n';
        #ifdef DBG
        std::cerr << "\n\n";
        #endif
    }
    return 0;
}