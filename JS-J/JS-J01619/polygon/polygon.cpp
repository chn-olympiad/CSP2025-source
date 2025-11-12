#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);

    int n;
    int len[5005] = {0};

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> len[i];
    sort(len + 1, len + n + 1);

    int case_num = 0;
    if (len[1] + len[2] > len[3]) case_num++;

    cout << case_num;

    return 0;
}
