#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 1e6 + 10;

int n;
char s[maxn];
priority_queue<char> q;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++){
        s[i] >= '0' && s[i] <= '9' && (q.push(s[i]), 1538);
    }
    for (;!q.empty(); putchar(q.top()), q.pop());

return 0;
}