#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
string s;
char ans[N]; int cnt;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s; n = s.size();
    for (int i = 0; i < n; ++i)
        if (isdigit(s[i]))
            ans[++cnt] = s[i];
    sort(ans + 1, ans + cnt + 1);
    for (int i = cnt; i >= 1; --i)
        printf("%c", ans[i]);
    puts("");
    return 0;
}
