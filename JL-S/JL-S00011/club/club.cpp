#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct student{
    int x;
    int y;
    int z;
};
struct pr{
    int mx;
    int pos;
    int sc;
};
bool cmp(pr a, pr b){
    return a.sc < b.sc;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        student s[N];
        pr p[N];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> s[i].x >> s[i].y >> s[i].z;
             p[i].mx = max(max(s[i].x, s[i].y),s[i].z);
             if(p[i].mx == s[i].x){
                p[i].pos = 1;
                p[i].sc = s[i].x - max(s[i].y, s[i].z);
             }
            else if(p[i].mx == s[i].y){
                p[i].pos = 2;
                p[i].sc = s[i].y - max(s[i].x, s[i].z);
             }
            else if(p[i].mx == s[i].x){
                p[i].pos = 3;
                p[i].sc = s[i].z - max(s[i].x, s[i].y);
             }
             ans += p[i].mx;
        }
        int t[3];
        for(int i = 1; i <= n; i++){
            t[p[i].pos]++;
        }
        int erro, times;
        for(int i = 1; i <= 3; i++){
            if(t[i] > n / 2){
                times = t[i] - n/2;
                erro = i;
            }
        }
        sort(p+1, p+n+1, cmp);
        for(int i = 1; i <= n; i++){
            if(p[i].pos == erro && times != 0){
                ans -= p[i].sc;
                times--;
            }
        }
        cout << ans << endl;
    }
return 0;
}
