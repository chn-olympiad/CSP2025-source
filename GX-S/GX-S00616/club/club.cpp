#include<iostream>
#include<algorithm>
using namespace std;

freopen("club.in", "r", stdin);
freopen("club.out", "w", stdout);

struct p
{
    int a;
    int b;
    int c;
};

int cmp(p a, p b)
{
    return a.a > b.a;
}

int main()
{
    int t, n;
    p a[100000];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j].a >> a[j].b >> a[j].c;
        }
        sort(a, a + n, cmp);
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            if (j < (n / 2))
            {
                s += a[j].a;
            }
            else
            {
                s += a[j].b;
            }
        }
        cout << s << endl;
    }
    return 0;
}