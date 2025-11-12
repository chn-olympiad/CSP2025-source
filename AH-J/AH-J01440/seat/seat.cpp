#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e6+5;

bool debug = 0;

ll n,m;
int a[400];
ll pos = 0;

void init()
{
    cin >> n >> m;
    for(register int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
        if(a[1] < a[i])
        {
            pos++;
        }
    }
    sort(a+1,a+1+n,greater<int>());
}

void work()
{
    ll k = pos / n + 1; // 规律题
    ll l;
    if((pos / n) % 2 == 0)
        l = (pos % n) + 1;
    else 
        l = n - (pos % n);
    cout << k << " " << l << endl;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    work();
    return 0;
}