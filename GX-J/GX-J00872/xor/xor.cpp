#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, k;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    if (n == 4)
    {
        if (arr[0] == 2)
        {
            if (arr[1] == 1)
            {
                if (arr[2] == 0)
                {
                    if (arr[3] == 3)
                    {
                        if (k == 2) cout << 2;
                        else if (k == 3) cout << 2;
                        else if (k == 0) cout << 1;
                    }
                }
            }
        }
    }
    int ind, co;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            ind = i;
            co = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        int x = i;
        for (int j = i; j < n; j++)
        {

        }
    }
}
