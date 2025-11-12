#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
int a[500010];
bool vis[500010];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            int su = a[i];
            bool flag = false;
            if(vis[i]) continue;
            for(int x = i+1;x <= j;x++)
            {
                if(vis[x]) 
                {
                    flag = true;
                    break;
                }
                su = su | a[x];
                vis[x] = true;
            }
            if(su == k && !flag) sum++;
        }
    }
    cout << sum <<endl;
    return 0;
}