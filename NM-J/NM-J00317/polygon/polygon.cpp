#include <bits/stdc++.h>
using namespace std;

int n, a[5005], b[5005], cnt, sum;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=n; i>=3; i--)
    {
        for(int j=0; j<=n-i; j++)
        {
            for(int k=j; k<i; k++)
            {
                cnt += a[k];
                b[k] = a[k];
            }
            sort(b+j, b+j+i+1, cmp);
            if(cnt>b[j])
            {
                sum++;
            }
            cnt = 0;
        }
    }
    cout << sum;
    return 0;
}
