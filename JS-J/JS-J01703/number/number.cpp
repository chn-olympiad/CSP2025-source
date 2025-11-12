#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<int> a;
    for (int i=0; i<int(s.size()); i++)
    {
        int tmp_int = int(s[i])-48;
        if (tmp_int >= 0 && tmp_int <= 9)
        {
            a.push_back(tmp_int);
        }
    }
    sort(a.begin(), a.end());
    for (int i=int(a.size())-1; i>=0; i--)
    {
        cout << a[i];
    }
    return 0;
}
