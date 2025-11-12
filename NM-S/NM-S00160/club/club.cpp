#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long t, n;
    long long men[100000][3];
    cin>>t;
    for (long long group = 0; group < t; group ++) {
        long long like_max_team[100000];
        long long likes[3] = {0, 0, 0};
        long long total = 0;
        long long team_max[3] = {INT_MIN, INT_MIN, INT_MIN};
        long long team_count[3] = {0, 0, 0};
        cin>>n;
        for (long long i = 0; i < n; i++) {
            for (long long team = 0; team < 3; team ++) {
                cin >> men[i][team];
            }
        }
        for (long long i = 0; i < n; i++) {
            long long max = INT_MIN;
            long long l_max;
            for (long long team = 0; team < 3; team ++) {
                if (men[i][team] > max) {
                    l_max = max;
                    max = men[i][team];
                    like_max_team[i] = team;
                }
            }
            if (team_count[like_max_team[i]] < n / 2) {
                team_count[like_max_team[i]] ++;
                total += max;
            }
            else {
                for (long long a = 0; a < n;a++) {
                    if (like_max_team[a] == like_max_team[i]) {
                        if (men[a][like_max_team[i]] < max) {
                            total -= men[a][like_max_team[i]];
                            total += max;
                            long long max = INT_MIN;
                            long long l_max;
                            for (long long team = 0; team < 3; team ++) {
                                if (men[i][team] > max && team != like_max_team[a]) {
                                    l_max = max;
                                    max = men[i][team];
                                    like_max_team[i] = team;
                                }
                            }
                            if (team_count[like_max_team[i]] < n / 2) {
                                team_count[like_max_team[i]] ++;
                                total += max;
                            }
                            break;
                        }
                    }
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}