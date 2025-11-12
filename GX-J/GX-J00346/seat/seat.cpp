#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m * n);
    for(int& i : p)
    {
        cin >> i;
    }
    int R = p[0];
    sort(p.begin(), p.end(), [](int a, int b)
    {
        return a > b;
    });
    for(int i = 0, n = p.size();i < n;++i)
    {
        if(p[i] == R) {
            cout << (i + 1) / n + 1 << " ";
            if(!(((i + 1) / n + 1) & 1)) {
                cout << n - i % n;
            } else {
                cout << i % n;
            }
            break;
        }
    }
    return 0;
}