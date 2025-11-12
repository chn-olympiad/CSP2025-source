#include <bits/stdc++.h>

using namespace std;
int k;
vector<int> stl;
bool fan(int a, int b)
{
    return !(a < b);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        stl.push_back(t);
    }
    sort(stl.begin(), stl.end(), fan);
    int co = 0;
    for (int i = 0; i < stl.size(); i++)
    {
        int Max = stl[i];
        int sum = Max;
        for (int j = i + 1; j < stl.size(); j++)
        {
            for (int l = j; l < stl.size(); l++)
            {
                sum += stl[l];
                if (sum > Max * 2)
                {
                    co++;
                }
            }
            sum = Max + stl[j];
        }
    }
    cout << (co - 2) % 998;
}
