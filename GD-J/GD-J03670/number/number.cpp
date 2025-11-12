#include <bits/stdc++.h>

using namespace std;

void out();

// string s;
char c;
int dig[1000010]{0}, cnt;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // getline(cin, s);
    while(cin >> c){
        if (c >= '0' && c <= '9')
            dig[cnt ++] = c - '0';
        if (c == EOF)
            break;
    }
    // for (int i = 0; i < s.size(); i ++){
    //     if (s[i] >= '0' && s[i] <= '9'){
    //         dig[cnt] = s[i] - '0';
    //         cnt ++;
    //     }
    // }
    sort(dig, dig + cnt, greater<int>());
    out();
    cout << '\n';
    return 0;
}

void out(){
    for (int i = 0; i < cnt; i ++){
        cout << dig[i];
    }
    return;
}



// freopen("number.in", "r", stdin);
// freopen("number.out", "w", stdout);

// feropen("number.in", "r", stdin);
// feropen("number.out", "w", stdout);

// freopen("number.in", "w", stdin);
// freopen("number.out", "r", stdout);

// freopen("number.in", "r", stdout);
// freopen("number.out", "w", stdin);