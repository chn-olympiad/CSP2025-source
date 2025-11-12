#include <bits/stdc++.h>
using namespace std;
int b[102];
int main()
{
int n,m;
cin >> n >> m;
for(int i = 1; i <= n*m; i++)
{
    cin >> b[i];
}
int c = b[1],cnt = 0;
for(int i = 1; i <= n*m; i++)
{
    if(b[i] > c)
    {
        cnt++;
    }
}
if(cnt % n == 0)
{
    int x = cnt/n;
    if(x % 2 == 0)
    {
        cout << x+1 << " " << 1;
    }
    else
    {
        cout << x+1 << " " << n;
    }
}
else
{
    int x = cnt/n;
    if(x % 2 == 0)
    {
        cout << x+1 << " " << cnt%n;
    }
    else
    {
        cout << x+1 << " " << n-cnt%n;
    }
}
return 0;
}
