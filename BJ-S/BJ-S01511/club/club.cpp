#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int N = 1e5 +5;

int t;
int n;
struct node{
    int a, b, c;
}M[N];
std::vector<node> S1, S2, S3;

bool cmp(node x, node y){
    return std::max({x.a, x.b, x.c}) >std::max({y.a, y.b, y.c});
}

node sorts(node x){
    node ret;
    int a[3] = {x.a, x.b, x.c};
    std::sort(a, a + 3);
    ret = node{a[0], a[1], a[2]};
    return ret;
}

bool cmp2(node x, node y){
    return x.b - x.c > y.b - y.c;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> t;

    while(t--){
        std::cin >> n;
        S1.clear();
        S2.clear();
        S3.clear();
        for(int i = 1; i <= n; ++i){
            int a, b, c;
            std::cin >> a >> b >> c;
            M[i] = node{a, b, c};
        }

        std::sort(M + 1, M + 1 + n, cmp);
        int ans = 0;
        int cnt1 = 0 ,cnt2 = 0, cnt3 = 0;
        for(int i = 1; i <= n; ++i){
            ans += std::max({M[i].a, M[i].b, M[i].c});
            if(M[i].a >= M[i].b && M[i].a >= M[i].c){
                ++cnt1;
                S1.push_back(sorts(M[i]));
            }else if(M[i].b >= M[i].a && M[i].b >= M[i].c){
                ++cnt2;
                S2.push_back(sorts(M[i]));
            }else{
                ++cnt3;
                S3.push_back(sorts(M[i]));
            }
        }
        if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
            std::cout << ans << '\n';
            continue;
        }
        if(cnt1 > n / 2){
            std::sort(S1.begin(), S1.end(), cmp2);
            for(int i = 0; i < S1.size(); ++i){
                if(cnt1 <= n / 2){
                    break;
                }
                ans += S1[i].b - S1[i].c;
                --cnt1;
            }
        }else if(cnt2 > n / 2){
            std::sort(S2.begin(), S2.end(), cmp2);
            for(int i = 0; i < S2.size(); ++i){
                if(cnt2 <= n / 2){
                    break;
                }
                ans += S2[i].b - S2[i].c;
                --cnt2;
            }
        }else{
            std::sort(S3.begin(), S3.end(), cmp2);
            for(int i = 0; i < S3.size(); ++i){
                if(cnt3 <= n / 2){
                    break;
                }
                ans += S3[i].b - S3[i].c;
                --cnt3;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
