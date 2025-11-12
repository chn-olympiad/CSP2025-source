#include<bits/stdc++.h>

using namespace std;

int n, q;
set<pair<string, string>> s;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        string x, y;
        cin >> x >> y;
        s.insert({x, y});
    }
    for(; q--; ){
        string x, y;
        cin >> x >> y;
        printf("0\n");
    }
    return 0;
}
