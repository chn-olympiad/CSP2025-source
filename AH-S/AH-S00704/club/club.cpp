//TLE 20pts
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, answer;
struct Club{
    int a, b, c;
    int maxn, minn, sum;
}club[N];
bool cmp(Club x, Club y) {
    if(x.minn == 0 || y.minn == 0) return x.maxn > y.maxn;
    return x.sum < y.sum;
}
bool cmpa(Club x, Club y) {
    if(x.sum != y.sum) return x.a > y.a;
    return x.sum < y.sum;
}
bool cmpb(Club x, Club y) {
    if(x.sum != y.sum) return x.b > y.b;
    return x.sum < y.sum;
}
bool cmpc(Club x, Club y) {
    if(x.sum != y.sum) return x.c > y.c;
    return x.sum < y.sum;
}
void dfs(int pos,int na,int nb,int nc,int val) {
    if(pos > n){
        answer = max(answer, val);
        //cout << val <<"\n";
        return ;
    }
    if(na < n / 2) dfs(pos + 1,na + 1,nb,nc,val + club[pos].a);
    if(nb < n / 2) dfs(pos + 1,na,nb + 1,nc,val + club[pos].b);
    if(nc < n / 2) dfs(pos + 1,na,nb,nc + 1,val + club[pos].c);
    return ;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //srand(time(nullptr));
    cin >> t;
    while (t--) {
        cin >> n;
        answer = 0;
        for (int i = 1; i <= n; i++) {
            cin >> club[i].a >> club[i].b >> club[i].c;
            club[i].maxn = max({club[i].a, club[i].b, club[i].c});
            club[i].minn = min({club[i].a, club[i].b, club[i].c});
            club[i].sum = club[i].a + club[i].b + club[i].c;
        }
        if(n <= 200) {
            dfs(1,0,0,0,0);
            cout << answer << "\n";
            continue;
        }

        int ansa = 0, ansb = 0, ansc = 0;
        sort(club + 1, club + n + 1, cmpa);
        for (int i = 1;i <= n / 2; i++) ansa += club[i].a;
        for (int i = n / 2 + 1;i <= n;i++) ansa += max(club[i].b, club[i].c);
        sort(club + 1, club + n + 1, cmpb);
        for (int i = 1;i <= n / 2; i++) ansb += club[i].b;
        for (int i = n / 2 + 1;i <= n;i++) ansb += max(club[i].a, club[i].c);
        sort(club + 1, club + n + 1, cmpc);
        for (int i = 1;i <= n / 2; i++) ansc += club[i].c;
        for (int i = n / 2 + 1;i <= n;i++) ansc += max(club[i].a, club[i].b);
        sort(club + 1, club + n + 1, cmp);
        int numa = 0, numb = 0, numc = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if(club[i].maxn == club[i].a) {
                if (numa < n / 2) {
                    ans += club[i].a;
                    numa++;
                    continue;
                } else {
                    if(club[i].b > club[i].c) {
                        ans += club[i].b;
                        numb++;
                        continue;
                    } else {
                        ans += club[i].c;
                        numc++;
                        continue;
                    }
                }
            }
            if(club[i].maxn == club[i].b) {
                if (numb < n / 2) {
                    ans += club[i].b;
                    numb++;
                    continue;
                } else {
                    if(club[i].a > club[i].c) {
                        ans += club[i].a;
                        numa++;
                        continue;
                    } else {
                        ans += club[i].c;
                        numc++;
                        continue;
                    }
                }
            }
            if(club[i].maxn == club[i].c) {
                if (numc < n / 2) {
                    ans += club[i].c;
                    numc++;
                    continue;
                } else {
                    if(club[i].a > club[i].b) {
                        ans += club[i].a;
                        numa++;
                        continue;
                    } else {
                        ans += club[i].b;
                        numb++;
                        continue;
                    }
                }
            }
        }
        cout << max({ansa, ansb, ansc, ans}) << "\n";

    }
    return 0;
}
