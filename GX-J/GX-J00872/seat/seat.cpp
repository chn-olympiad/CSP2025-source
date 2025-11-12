#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> seat_m;
bool fan(int a, int b)
{
    return !(a < b);
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        int j;
        cin >> j;
        seat_m.push_back(j);
    }
    int rcj = seat_m[0];
    sort(seat_m.begin(), seat_m.end(), fan);
    int ind;
    for (int i = 0; i < seat_m.size(); i++)
    {
        if (seat_m[i] == rcj)
        {
            ind = i;
            break;
        }
    }
    int lie = ind / m + 1;
    int hang;
    if (lie % 2 == 0)
        if (ind % n == 0) hang = 1;
        else hang = n - ind % n;
    else {
        hang = ind % n + 1;
    }
    cout << lie << " " << hang;
}
