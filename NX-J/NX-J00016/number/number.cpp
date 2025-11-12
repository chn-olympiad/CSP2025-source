#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000005], cnt;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n.size(); i++)
    {
        if(n[i] >= '0' && n[i] <= '9')
        {
            a[cnt] = n[i] - 48;
            cnt += 1;
        }
    }
    sort(a, a + cnt, cmp);
    for(int i = 0; i < cnt; i++)
    {
        cout << a[i];
    }
    return 0;
}
