#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int T;
int n;
struct Stu{
    int a[4];
    int b, c;
    bool operator< (const Stu &B) const {
        return a[b] - a[c] > B.a[B.b] - B.a[B.c];
    }
}s[N];

void solve(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++)
            scanf("%d", &s[i].a[j]);
        s[i].a[3] = -1;
        s[i].b = s[i].c = 3;
        for(int j = 0; j < 3; j++)
            if(s[i].a[j] >= s[i].a[s[i].b])
                s[i].c = s[i].b, s[i].b = j;
            else if(s[i].a[j] >= s[i].a[s[i].c])
                s[i].c = j;
    }
    sort(s + 1, s + n + 1);
    /*for(int i = 1; i <= n; i++)
        printf("%d %d %d %d %d\n", s[i].a[0], s[i].a[1], s[i].a[2], s[i].b, s[i].c);*/

    long long ans = 0;
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[s[i].b] >= n / 2){
            ans += s[i].a[s[i].c];
            cnt[s[i].c]++;
        }else{
            ans += s[i].a[s[i].b];
            cnt[s[i].b]++;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
