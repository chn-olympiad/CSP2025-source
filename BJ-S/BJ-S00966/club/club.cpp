#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, delta1[maxn], delta2[maxn], cnt1, cnt2, cnt3, ans;
struct navi{
    int a, b, c, pos;
    friend bool operator < (const navi num1, const navi num2){
        if(delta1[num1.pos] == delta1[num2.pos] && delta2[num1.pos] == delta2[num2.pos])
            return max({num1.a, num1.b, num1.c}) > max({num2.a, num2.b, num2.c});
        else if (delta1[num1.pos] == delta1[num2.pos])
            return delta2[num1.pos] > delta2[num2.pos];
        return delta1[num1.pos] > delta1[num2.pos];
    }
}satisf[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> satisf[i].a >> satisf[i].b >> satisf[i].c;
            satisf[i].pos = i;
            int max_sat = max({satisf[i].a, satisf[i].b, satisf[i].c});
            int min_sat = max({satisf[i].a, satisf[i].b, satisf[i].c});
            int mid_sat = satisf[i].a + satisf[i].b + satisf[i].c - max_sat - min_sat;
            delta1[i] = max_sat - mid_sat;
            delta2[i] = mid_sat - max_sat;
        }
        sort(satisf + 1, satisf + 1 + n);
        cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            if(satisf[i].a > satisf[i].b && satisf[i].a > satisf[i].c){
                if(cnt1 == n / 2){
                    if(satisf[i].b > satisf[i].c){
                        if(cnt2 == n / 2){
                            cnt3++;
                            ans += satisf[i].c;
                        }
                        else{
                            cnt2++;
                            ans += satisf[i].b;
                        }
                    }
                    else{ // c > b
                        if(cnt3 == n / 2){
                            cnt2++;
                            ans += satisf[i].b;
                        }
                        else{
                            cnt3++;
                            ans += satisf[i].c;
                        }
                    }
                }
                else{
                    cnt1++;
                    ans += satisf[i].a;
                }
            }
            else if(satisf[i].b > satisf[i].a && satisf[i].b > satisf[i].c){
                if(cnt2 == n / 2){
                    if(satisf[i].a > satisf[i].c){
                        if(cnt1 == n / 2){
                            cnt3++;
                            ans += satisf[i].c;
                        }
                        else{
                            cnt1++;
                            ans += satisf[i].a;
                        }
                    }
                    else{ // c > a
                        if(cnt3 == n / 2){
                            cnt1++;
                            ans += satisf[i].a;
                        }
                        else{
                            cnt1++;
                            ans += satisf[i].a;
                        }
                    }
                }
                else{
                    cnt2++;
                    ans += satisf[i].b;
                }
            }
            else if(satisf[i].c > satisf[i].b && satisf[i].c > satisf[i].a){
                if(cnt3 == n / 2){
                    if(satisf[i].b > satisf[i].a){
                        if(cnt2 == n / 2){
                            cnt1++;
                            ans += satisf[i].a;
                        }
                        else{
                            cnt2++;
                            ans += satisf[i].b;
                        }
                    }
                    else{ // a > b
                        if(cnt1 == n / 2){
                            cnt2++;
                            ans += satisf[i].b;
                        }
                        else{
                            cnt1++;
                            ans += satisf[i].a;
                        }
                    }
                }
                else{
                    cnt3++;
                    ans += satisf[i].c;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
