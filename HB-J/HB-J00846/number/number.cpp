#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005], num[1000005];
int main(){
    freopen("number.in", "r",  stdin);
    freopen("number.out", "w", stdout);
    scanf(" %s", s);
    ll len = strlen(s), cnt = 0, i;
    for(i = 0;i < len;i++)
        if(isdigit(s[i])) num[cnt++] = s[i];
    sort(num, num + cnt, greater<int>());
    if(num[0] == '0'){putchar('0'); return 0;}
    for(i = 0;i < cnt;i++) printf("%c", num[i]);
    return 0;
}
