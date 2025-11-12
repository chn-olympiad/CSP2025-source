#include <bits/stdc++.h>
using namespace std;

pair<int, int> tres_sort(int a, int b, int c) {
    if(a >= b && b >= c) {
        return {0, 1};
    }
    if(a >= c && c >= b) {
        return {0, 2};
    }
    if(b >= c && c >= a) {
        return {1, 2};
    }
    if(b >= a && a >= c) {
        return {1, 0};
    }
    if(c >= a && a >= b) {
        return {2, 0};
    }
    if(c >= b && a >= a) {
        return {2, 1};
    }
    return {0, 0};
}

void facit() {
    int n; cin >> n;
    array<vector<int>, 3> clubs;
    long long sum = 0;
    for(int j = 0; j < n; ++j) {
        array<int, 3> dat;
        cin >> dat[0] >> dat[1] >> dat[2];
        pair<int, int> s = tres_sort(dat[0], dat[1],dat[2]);
        clubs[s.first].push_back(dat[s.first] - dat[s.second]);
        sum += dat[s.first];
    }
    int m = tres_sort(clubs[0].size(), clubs[1].size(), clubs[2].size()).first;
    if(clubs[m].size() > n/2) {
        sort(clubs[m].begin(), clubs[m].end());
        for(int j = 0; j < clubs[m].size() - n/2; ++j) {
            sum -= clubs[m][j];
        }
    }
    cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    for(int j = 0; j < t; ++j) {
        facit();
    }
    return 0;
}

