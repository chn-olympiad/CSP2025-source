#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    int sums[n];
    cin >> a[0];
    sums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        sums[i] = sums[i - 1] ^ a[i];
    }
    int cnt = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = sums[i];
        if (index > 0)
            sum ^= sums[index - 1];
        for (int j = index; j <= i; j++)
        {
            if (a[j] == k)
            {
                cnt++;
                index = j + 1;
            }
            else if (sum == k)
            {
                cnt++;
                index = i + 1;
                break;
            }
            sum ^= a[j];
        }
    }
    cout << cnt;
    return 0;
}
