#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
char s[N];
string t;

bool comp(const char& si, const char& sj){
    return si > sj;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    for (int i = 0; s[i] != 0; i++){
        if ('0' <= s[i] && s[i] <= '9')
            t.push_back(s[i]);
    }
    sort(t.begin(), t.end(), comp);
    cout << t;
    return 0;
}

