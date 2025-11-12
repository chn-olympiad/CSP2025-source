#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N],cnt;

bool cmd(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++)
        if('0' <= s[i] && s[i] <= '9')
            a[++cnt] = (int(s[i]) - 48);
    sort(a+1,a+1+cnt,cmd);
    for(int i = 1;i <= cnt;i++)
        cout << a[i];
    return 0;
}
