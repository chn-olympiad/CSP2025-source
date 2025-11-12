#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
char s[N];
priority_queue<int> q;
int n;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
        if(s[i] >= '0' && s[i] <= '9')
            q.push(s[i] - '0');
    while(!q.empty()){
        printf("%d", q.top());
        q.pop();
    }
    puts("");
    return 0;
}
