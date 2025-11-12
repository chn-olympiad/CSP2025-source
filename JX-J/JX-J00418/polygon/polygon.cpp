#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    vector <int> a;
    for(int i = 1;i <= n;i++)
    {
        int w;
        cin >> w;
        a.push_back(w);
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 1;j < n;j++)
        {
            for(int z = 2;z < n;z++)
            {
                if(a[i] + a[j] > a[z] && a[i] + a[z] > a[j] && a[j] + a[z] > a[i])
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt / 4 - 2 << endl;
    return 0;
}
