/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T
    cin >> T;
    while(T--)
    {
        int n = 0;
        cin >> n;
        vector<int> a[5];
        a[1].push_back(0);
        a[2].push_back(0);
        a[3].push_back(0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; i <= 3; j++)
            {
                int a1, a2, a3;
                cin >> a1 >> a2 >> a3;
                a[1].push_back(a1);
                a[2].push_back(a2);
                a[3].push_back(a3);
            }
        }
        // ......
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n = 0;
        cin >> n;
        if(n == 2)
        {
            int a[15] = {0};
            for(int i = 1; i <= n * 3; i++)
                cin >> a[i];
            sort(a + 1, a + n * 3 + 1);
            cout << a[6] + a[5] + a[4] << "\n";
        }
    }

    return 0;
}
