#include<bits/stdc++.h>
using namespace std;
int one[100005], two[100005], three[100005], maxx[100005];

int mnx(int aa, int bb, int cc)
{
    return max(aa, max(bb, cc));
}
int main()
{
    int t = 0;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n = 0, a = 0, b = 0, c = 0;
        cin >> n;
        for(int j = 1; j <= n; j++)
            cin >> one[j] >> two[j] >> three[j];
        for(int j = 1; j <= n; j++)
        {
            a += one[j];
            b += two[j];
            c += three[j];
        }
        if(b == 0 && c == 0)
        {
            sort(one + 1, one + n + 1);
            for(int j = n; j > n/2; j--)
                maxx[i] += one[j];
        }
        if(a == 0 && c == 0)
        {
            sort(two + 1, two + n + 1);
            for(int j = n; j > n/2; j--)
                maxx[i] += two[j];
        }
        if(a == 0 && b == 0)
        {
            sort(three + 1, three + n + 1);
            for(int j = n; j > n/2; j--)
                maxx[i] += three[j];
        }
        if(a != 0 && b != 0 && c != 0)
        {
            for(int j = 1; j <= n; j++)
                maxx[i] += mnx(one[j], two[j], three[j]);
        }
    }
    for(int i = 1; i <= t; i++)
        cout << maxx[i] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
