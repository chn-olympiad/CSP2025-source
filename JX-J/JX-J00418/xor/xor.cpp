#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0;
    cin >> n >> k;
    vector <int> a;
    for(int i = 1;i <= n;i++)
    {
        int w;
        cin >> w;
        a.push_back(w);
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(a[i] + a[j] == k)
            {
                cnt++;
            }
        }
    }
    if(k == 0)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << cnt - k + 1 << endl;
    }
    return 0;
}
