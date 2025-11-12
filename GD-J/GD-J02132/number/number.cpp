#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char s[1000010];
    cin >> s;
    int cnt[10];
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= '0' && s[i] <= '9')
            cnt[s[i] - '0']++;
        i++;
    }
    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < cnt[i]; j++)
            cout << i;
    return 0;
}
