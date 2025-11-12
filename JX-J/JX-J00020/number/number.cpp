#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    long long cnt=0;
    char b[1000005];
    cin >> a;
    long long n = a.length();
    for (int i = 0;i < n;i++)
    {
        if((a[i] <= '9')&&(a[i] >= '0'))
        {
            cnt++;
            b[cnt] = a[i];
        }
    }
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    for(int i = 1;i <= cnt;i++)
    {
        cout << b[i];
    }
    return 0;
}
