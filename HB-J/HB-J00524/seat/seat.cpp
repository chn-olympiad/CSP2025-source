#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
int pos;
int x, y;
int px = 1, py = 1;
bool cmp(int b, int c)
{
    return b > c;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> x >> y;
    int n = x * y;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pos = a[1];
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == pos)
        {
            cout << py << " " << px;
            return 0;
        }
        else
        {
            if(py % 2 != 0)
            {
                if(px < x)
                {
                    ++px;
                }
                else
                {
                    ++py;
                }
            }
            else
            {
                if(px > 1)
                {
                    --px;
                }
                else
                {
                    ++py;
                }
            }
        }
    }
    return 0;
}
