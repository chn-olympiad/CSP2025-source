#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++)
    {
        cin >> s[i];
    }
    int mark = s[1];
    sort(s+1,s+n*m+1,cmp);
    int number;
    for(int i = 1; i <= n*m; i++)
    {
        if(mark == s[i])
        {
            number = i;
            break;
        }
    }
    if(number >= 1 && number <= n)
    {
        cout << 1 << " " << number;
    }
    else
    {
        int k = number/n;
        int p = number%n;
        if(k%2 == 1)
        {
            if(p == 0)
            {
                cout << k << " " << n;
            }
            else
            {
                cout << k+1 << " " << n-p+1;
            }
        }
        else
        {
            if(p == 0)
            {
                cout << k << " " << 1;
            }
            else
            {
                cout << k+1 << " " << p;
            }
        }
    }
    return 0;
}