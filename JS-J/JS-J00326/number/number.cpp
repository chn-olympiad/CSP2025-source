#include <bits/stdc++.h>
#define int long long
using namespace std;

char a[1000010];

bool cmp(char x , char y)
{
    return x > y;
}

signed main()
{
    //ctrl + s!!!!!!
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    int cnt = 0;
    char c;
    while(cin >> c)
    {
        if(c >= '0' && c <= '9') a[++cnt] = c;
    }
    sort(a + 1 , a + cnt + 1 , cmp);
    //cout << cnt << endl;
    for(int i = 1;i <= cnt;i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
