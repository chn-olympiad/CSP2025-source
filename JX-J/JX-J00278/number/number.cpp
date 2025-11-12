#include<bits/stdc++.h>

using namespace std;

char s[1000010];
int n, len;
int a[1000010];

bool cmp(const int &x, const int &y){
    return x > y;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    len = strlen(s + 1);
    for(int i = 1; i <= len; i++)
        if(s[i] >= '0' && s[i] <= '9')
            a[++n] = s[i] - '0';
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        printf("%d", a[i]);
    return 0;
}
