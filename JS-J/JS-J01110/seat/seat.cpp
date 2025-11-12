#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, a[1001], x, y;
bool f;
bool cmp(int w, int s) {return w > s;}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    p = n * m;
    for(int i = 1;i <= p;i++) cin >> a[i];
    q = a[1];
    sort(a + 1, a + p + 1, cmp);
    for(int i = 1;i <= p;i++) cout << a[i] << " ";
    cout << endl;
    f = 1, x = 1, y = 1;
    for(int i = 1;i <= p;i++)
    {
        if(a[i] == q) 
        {
            cout << y << " " << x << endl;
            return 0;
        }
        if(x == 1 && f == 0) y++, f = !f;
        else if(x == n && f == 1) y++, f = !f;
        else if(f == 0) x--;
        else x++;
    }
    return 0;
}