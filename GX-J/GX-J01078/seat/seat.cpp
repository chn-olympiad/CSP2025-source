#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int nm = n * m;
    vector<int> a(nm + 3);
    for(int i = 0; i < nm; i++)
    {
        cin >> a[i];
    }
    int mark = a[0];
    sort(a.begin(), a.end(), greater<int>());
    int num;
    for(int i = 0; i < nm; i++)
    {
        if(a[i] == mark)
        {
            num = i + 1;
            break;
        }
    }
    int lie = ceil(1.0 * num / m);
    int hang = num;
    if(hang != m)
        hang %= m;
    if(hang == 0)
        hang = m;
    if(lie % 2 == 0)
    {
        cout << lie << " " << (m - hang + 1);
    }
    else
    {
        cout << lie << " " << hang;
    }
    return 0;
}
