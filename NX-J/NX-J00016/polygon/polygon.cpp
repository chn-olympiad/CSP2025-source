#include<bits/stdc++.h>
using namespace std;
int n, a[5005], s, m, cnt;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 0 ;i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            for(int k = i; k < j; k++)
            {
                m += a[k];
                s = a[k];
            }
            if(m > s * 2)
            {
                cnt++;
                cout << m << " " << s * 2 << endl;
            }
            s = 0;
            m = 0;
        }
    }
    cout << cnt;
    return 0;
}
