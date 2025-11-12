#include <iostream>
using namespace std;
int main()
{
    int R = 0, ans = 0, s[100];
    cin >> R;
    for (int i = 1;i <= R;i++)
    {
        cin >> s[i];
    }
    for (int i = 1;i <= R;i++)
    {
        for (int j = i;j <= R;j++)
        {
            for (int w = j;w <= R;w++)
            {
                if(s[i] + s[j] + s[w] > 2 * s[w])
                {
                    ans++;
                }
                if (i == j && i == w && j == w)
                {
                    ans--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
