#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int pair_num, query_num;
    cin >> pair_num >> query_num;

    map<string, string> pairs;
    for (int i = 0; i < pair_num; i++){
        string str_first, str_second;
        cin >> str_first >> str_second;
        pairs[str_first] = str_second;
    }

    while (query_num--){
        string str_a, str_b;
        cin >> str_a >> str_b;

        int size = str_a.size(), start = -1, end = -1;
        for (start = 0; start < size; start++) if (str_a[start] != str_b[start]) break;
        for (end = size - 1; end >= 0; end--) if (str_a[end] != str_b[end]) break;

        vector<string> pref(size + 1, "");
        for (int i = 0; i < size; i++) pref[i + 1] = pref[i] + str_a[i];
        vector<string> suff(size + 1, "");
        for (int i = 0; i < size; i++) suff[size - i - 1] = str_a[size - i - 1] + suff[size - i];

        int ans = 0;
        string raw = str_a.substr(start, end - start + 1);
        for (int l = start; l >= 0; l--){
            string mid = raw;
            for (int r = end; r < size; r++){
                if (pref[l] + pairs[mid] + suff[r + 1] == str_b) ans++;
                if (r + 1 < size) mid += str_b[r + 1];
            }
            if (l - 1 >= 0) raw = str_a[l - 1] + raw;
        }

        cout << ans << "\n";
    }

    return 0;
}
