#include <iostream>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r = 0;
    cin >> n >> m;
    int s[n*m] = {};
    for (int i = 1;i <= n*m;i++)
    {
        cin >> s[i];
        if (i == 1)
        {
            r = s[i];
        }
    }
    for (int i = 1;i <= n*m;i++)
    {
        for (int j = i;j <= n*m;j++)
        {
            if (s[i] <= s[j])
            {
                int h = s[j];
                s[j] = s[i];
                s[i] = h;
            }
        }
    }
    int seat = 0;
    for (int i = 1;i <= n*m;i++)
    {
        if (s[i] == r)
        {
            seat = i;
            break;
        }
    }
    if (seat <= m)
    {
        cout << 1 << " " << seat;
        return 0;
    }
    //cout << seat / m + 1;
    if ((seat / m + 1)%2 == 0 && seat % m != 0)
    {
        cout << seat / m + 1 << " " << seat % m+1;
        return 0;
    }
    if (seat % m != 0)
    {
        cout << seat / m  + 1<< " " << seat % m;
        return 0;
    }
    return 0;
}
