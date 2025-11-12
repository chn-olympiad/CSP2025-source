#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int cnt;
        cin >> cnt;
        int maxn = 0;
        for(int j = 0;j < cnt;j++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(a > b && a > c)
            {
                maxn += a;
                continue;
            }
            if(b > a && b > c)
            {
                maxn += b;
                continue;
            }
            if(c > a && c > b)
            {
                maxn += c;
                continue;
            }
        }
        cout << maxn << endl;
    }
    return 0;
}
