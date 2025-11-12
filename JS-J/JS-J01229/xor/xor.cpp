#include <bits/stdc++.h>
using namespace std;

int a[500005];
int s[500005];
int jsq;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    s[1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        s[i] = s[i - 1] ^ a[i - 1];
    }
    for(int i = n; i >= 1; i--)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(s[i] ^ s[j] == k)
            {
                jsq++;
                i = j;
                break;
            }
        }
    }
    cout << jsq << endl;
    return 0;
}
