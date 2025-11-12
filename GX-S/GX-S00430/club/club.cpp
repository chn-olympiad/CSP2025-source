#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_num;
    cin >> test_num;

    while (test_num--){
        int num;
        cin >> num;
        int max_size = num / 2;

        long long total = 0;
        vector<int> size(3, 0);
        vector<int> match(num, -1);
        vector<pair<pair<long long, int>, pair<int, int>>> subtract;
        for (int i = 0; i < num; i++){
            vector<pair<long long, int>> val(3);
            for (int i = 0; i < 3; i++){
                cin >> val[i].first;
                val[i].second = i;
            }
            sort(val.begin(), val.end(), greater<pair<long long, int>>());

            total += val[0].first;
            size[val[0].second]++;
            match[i] = val[0].second;
            subtract.push_back({{val[1].first - val[0].first, i}, {val[0].second, val[1].second}});
            subtract.push_back({{val[2].first - val[0].first, i}, {val[0].second, val[2].second}});
            subtract.push_back({{val[2].first - val[1].first, i}, {val[1].second, val[2].second}});
        }
        sort(subtract.begin(), subtract.end(), greater<>());

        for (const auto &it : subtract){
            if (size[0] <= max_size && size[1] <= max_size && size[2] <= max_size) break;

            long long dis_contrib = it.first.first;
            int ind = it.first.second, from = it.second.first, to = it.second.second;

            if (match[ind] != from || size[from] <= size[to] || (size[from] <= max_size && size[to] <= max_size)) continue;
            match[ind] = to;
            total += dis_contrib;
            size[from]--;
            size[to]++;
        }

        cout << total << "\n";
    }

    return 0;
}
