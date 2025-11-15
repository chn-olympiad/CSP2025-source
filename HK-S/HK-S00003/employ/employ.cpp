#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
string s;
int c[N];
inline bool check(string ord){
    int fcnt = 0;
    for (int i = 0; i < ord.size(); i++){
        int x = ord[i] - '0' + 1;
        if (fcnt >= c[x] || s[i] == '0'){
            fcnt++;
        }
    }
    return (n - fcnt) >= m;
}
inline void sub1(){
    int cnt = 0, fac = 1;
    string s = "";
    for (int i = 0; i < n; i++){
        s.push_back(i + '0');
        fac *= i + 1;
    }
    for (int i = 0; i < fac; i++){
        if (check(s)){
            cnt++;
        }
        next_permutation(s.begin(), s.end());
    }
    printf("%d\n", cnt);
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    cin >> s;
    for (int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    sub1();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


