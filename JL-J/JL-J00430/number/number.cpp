#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)

const int N = 1000050;
int n, a[15];
char s[N];
string t;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    rep(i, 1, n)
        if(s[i] >= '0' && s[i] <= '9')
            a[s[i] - '0']++;
    per(i, 9, 0)
        rep(j, 1, a[i])
            t += (i + '0');
    cout << t << '\n';
}
