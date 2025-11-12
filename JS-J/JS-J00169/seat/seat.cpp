#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, cnt=0;
    cin >> n >> m;
    int seat[n+5][m+5] = {}, num[105];
    queue<int> a;
    for(int i=0; i<105; i++)
        num[i] = -1;
    for(int i=1; i<=n*m; i++)
    {
        cin >> num[i];
    }
    cnt = num[1];
    sort(num+0, num+105);
    for(int i=104; i>=0; i--)
    {
        if(num[i] != -1)
            a.push(num[i]);
    }
    for(int i=1; i<=m; i++)
    {
        int j=1;
        if(j==1)
        {
            for(j=1; j<=n; j++)
            {
                if(a.front() == cnt)
                {
                    cout << i << " " << j;
                    return 0;
                }
                seat[j][i] = a.front();
                a.pop();
            }
            j = n;
        }
        else if(j==n)
        {
            for(j=n; j>=1; j--)
            {
                if(a.front() == cnt)
                {
                    cout << i << " " << j;
                    return 0;
                }
                seat[j][i] = a.front();
                a.pop();
            }
            j = 1;
        }
    }
    return 0;
}
