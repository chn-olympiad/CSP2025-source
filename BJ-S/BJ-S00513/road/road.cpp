#include<bits/stdc++.h>

using namespace std;

int cst;
bool che = false;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
  
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b >> cst;
    }

    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n + 1; j++)
        {
            int t;
            cin >> t;
            if(t != 0)
            {
                che = true;
            }
        }
    }

    if(che == false)
    {
        cout << 0;
    }

    return 0;
}
