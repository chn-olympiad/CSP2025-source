#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e6+5;

ll n,m;
string s;
int a[maxn];
ll cnt;

void init()
{
    cin >> s;
    for(auto c : s)
    {
        if('0' <= c && c <= '9' )
            a[++cnt] = c - '0';
    }
    sort(a+1,a+1+cnt,greater<int>());
}

void work()
{
    for(register ll i = 1;i <= cnt;i++)
    {
        cout << a[i];
    }
    cout << endl;
    return;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    init();
    work();
    return 0;
}