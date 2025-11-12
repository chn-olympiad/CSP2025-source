#include <bits/stdc++.h>
using namespace std;
int a[1000005], s = '1';
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n = 0;
    while((s <= '9' && s >= '0') || (s >= 'a' && s <= 'z')){
        scanf("%c", &s);
        if(s <= '9' && s >= '0'){
            a[++n] = s - '0';
        }
    }
    sort(a+1, a+n+1);
    for(int i = n; i >= 1; i--) printf("%d", a[i]);
    return 0;
}
