// GZ-S00305 贵阳市花溪区湖潮中学 王一帆
#include <bits/stdc++.h>
using namespace std;

bool compPersonsScores(vector<int> v1, vector<int> v2) {
    if (v1[1] > v2[1]) {
        return true;
    } else {
        return false;
    }
}

void sortPersonsScores(vector<vector<int>> &vect)
{
    sort(vect.begin(), vect.end(), compPersonsScores);
}

bool compHighestScorePersonForClub(vector<vector<int>> v1, vector<vector<int>> v2) {
    if (v1[0][1] > v2[0][1]) {
        return true;
    } else {
        return false;
    }
}

void sortHighestScorePersonForClub(vector<vector<vector<int>>> &vect)
{
    sort(vect.begin(), vect.end(), compHighestScorePersonForClub);
}

void func()
{
    int n, max, best = 0, g1, g2, g3;
    cin >> n;
    max = n / 2;
    vector<vector<vector<int>>> good;
    // member: {1: x, 2: x, 3: x}
    vector<vector<int>> clubs = {
        {0, 0},
        {0, 0},
        {0, 0}
        // member, score
    };
    for (int i; i < n; i++)
    {
        cin >> g1;
        cin >> g2;
        cin >> g3;
        good.push_back({{0, g1},
                        {1, g2},
                        {2, g3}});
        sortPersonsScores(good[i]);
    }

    // cout << "max: " << max << endl;

    sortHighestScorePersonForClub(good);

    for (vector<vector<int>> p : good)
    {
        // cout << "--" << endl;
        // cout << p[0][0] << ": " << p[0][1] << endl;
        // cout << p[1][0] << ": " << p[1][1] << endl;
        // cout << p[2][0] << ": " << p[2][1] << endl;

        for (vector<int> clb : p)
        {
            if (clubs[clb[0]][0] < max)
            {
                // cout << "got club " << clb[0] << ", append " << clb[1] << endl;
                clubs[clb[0]][0]++;
                clubs[clb[0]][1] += clb[1];
                break;
            }
        }
    }

    // cout << "club count: " << endl;
    // cout << "#0: " << clubs[0][0] << " people, score: " << clubs[0][1] << endl;
    // cout << "#1: " << clubs[1][0] << " people, score: " << clubs[1][1] << endl;
    // cout << "#2: " << clubs[2][0] << " people, score: " << clubs[2][1] << endl;
    // cout << clubs[0][1] + clubs[1][1] + clubs[2][1] << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;

    while (t > 0)
    {
        func();
        t--;
    }
    return 0;
}