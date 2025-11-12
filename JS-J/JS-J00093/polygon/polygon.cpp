#include<bits/stdc++.h>

#define N 998244353

using namespace std;

int n;
int sum = 0;
int l[5005] = {0};

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> l[i];
    }

    for(int i = 0; i < n - 2; i ++)
    {
        for(int j = i + 1; j < n - 1; j ++)
        {
            for(int k = j + 1; k < n; k ++)
            {
                if(l[i] + l[j] < l[k])
                {
                    sum ++;
                }
            }
        }
    }
    cout << sum << endl;
    fclose(stdin);
    fclose(stdout);

    return 0;
}

