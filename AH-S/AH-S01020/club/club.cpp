#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct node{
    ll a, b, c;
    bool f;
}a[N];
bool cmpa(const node &x, const node &y){
    return x.a - max(x.b, x.c) > y.a - max(y.b, y.c);
}
bool cmpb(const node &x, const node &y){
    return x.b - max(x.a, x.c) > y.b - max(y.a, y.c);
}
bool cmpc(const node &x, const node &y){
    return x.c - max(x.a, x.b) > y.c - max(y.a, y.b);
}
bool cmpA(const node &x, const node &y){
    return x.a > y.b;
}
ll t, n, ans, num, cnta, cntb, cntc;
void dfs(int cur){
    if(cur >= n + 1){
        ans = max(ans, num);
        return;
    }
    if(cnta < n/2){
        cnta++;
        num += a[cur].a;
        dfs(cur + 1);
        cnta--;
        num -= a[cur].a;
    }
    if(cntb < n/2){
        cntb++;
        num += a[cur].b;
        dfs(cur + 1);
        cntb--;
        num -= a[cur].b;
    }
    if(cntc < n/2){
        cntc++;
        num += a[cur].c;
        dfs(cur + 1);
        cntc--;
        num -= a[cur].c;
    }
}
bool xzA = 1;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(int i=1; i<=n; i++){
            scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
            a[i].f = 0;
            if(a[i].b != 0 || a[i].c != 0) xzA = 0;
        }
        if(xzA){
            ans = 0;
            sort(a+1, a+n+1, cmpA);
            for(int i=1; i<=n/2; i++) ans += a[i].a;
            printf("%lld\n", ans);
            continue;
        }
        cnta = cntb = cntc = 0;
        if(n <= 10){
            ans = num = 0;
            dfs(1);
            printf("%lld\n", ans);
            continue;
        }
        ll maxn = 0, sum = 0;
        sort(a+1, a+n+1, cmpa);
        for(int i=1; i<=n; i++){
            if(a[i].a > a[i].b && a[i].a > a[i].c){
                maxn += a[i].a;
                cnta++;
                a[i].f = 1;
                if(cnta >= n/2) break;
            }
        }
        sort(a+1, a+n+1, cmpb);
        for(int i=1; i<=n; i++){
            if(a[i].f == 0 && a[i].b > a[i].c){
                maxn += a[i].b;
                cntb++;
                a[i].f = 1;
                if(cntb >= n/2) break;
            }
        }
        for(int i=1; i<=n; i++){
            if(a[i].f == 0){
                if(cntc == n/2){
                    if(a[i].a > a[i].b){
                        maxn += a[i].a;
                        cnta++;
                        a[i].f = 1;
                    }
                    else{
                        maxn += a[i].b;
                        cntb++;
                        a[i].f = 1;
                    }
                }
                else if(cntb == n/2){
                    if(a[i].a > a[i].c){
                        maxn += a[i].a;
                        cnta++;
                        a[i].f = 1;
                    }
                    else{
                        maxn += a[i].c;
                        cntc++;
                        a[i].f = 1;
                    }
                }
                else if(cnta == n/2){
                    if(a[i].b > a[i].c){
                        maxn += a[i].b;
                        cntb++;
                        a[i].f = 1;
                    }
                    else{
                        maxn += a[i].c;
                        cntc++;
                        a[i].f = 1;
                    }
                }
                else{
                    ll maxl = max(a[i].a, max(a[i].b, a[i].c));
                    if(a[i].a == maxl){
                        maxn += a[i].a;
                        cnta++;
                        a[i].f = 1;
                    }
                    else if(a[i].b == maxl){
                        maxn += a[i].b;
                        cntb++;
                        a[i].f = 1;
                    }
                    else{
                        maxn += a[i].c;
                        cntc++;
                        a[i].f = 1;
                    }
                }
            }
            if(cnta + cntb + cntc == n) break;
        }
        printf("%lld\n", maxn);
    }
    return 0;
}
