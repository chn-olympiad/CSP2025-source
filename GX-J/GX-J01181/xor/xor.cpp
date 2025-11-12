#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n , k;
    cin >> n >> k;

    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    if(k == 0)
    {
        cout << 1;
        return 0;
    }

    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int cnt = a[i];
        for(int j = i + 1 ; j < n ; j++)
        {
            if(cnt == k)
                sum = max(sum , j - i);
            cnt += cnt ^ a[j];
        }
    }
    cout << sum;

    return 0;
}
