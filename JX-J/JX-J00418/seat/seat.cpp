#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,max = 0,tmp = 0,f = 0;
    cin >> n >> m;
    vector <int> a;
    vector <int> v;
    for(int i = 1;i <= n * m;i++)
    {
        int w;
        cin >> w;
        a.push_back(w);
    }
    tmp = a[0];
    for(int i = 0;i < n * m;i++)
    {
        max = 0;
        f = 0;
        for(int j = 0;j < n * m;j++)
        {
            if(a[j] == -1)
            {
                j++;
            }
            if(a[j] > max)
            {
                max = a[j];
                f = j;
            }
        }
        v.push_back(max);
        a[f] = -1;
    }
    for(int i = 0;i < n * m;i++)
    {
        if(a[i] == tmp)
        {
            f = i;
        }
    }
    int c = f / n;
    cout << c << ' ';
    if(f / m % 2 == 0)
    {
        int r = f % m;
        cout << r << endl;
    }
    else
    {
        int r = m - f % m;
        cout << r << endl;
    }
    return 0;
}
