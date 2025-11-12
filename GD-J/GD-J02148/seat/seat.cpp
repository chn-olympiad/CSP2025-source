#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int st[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int R = 0,seat = 0,x = 0,y = 0;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> st[i];
        st[i] = -st[i];
        if(i == 1)
        {
            R = st[i];
        }
    }
    sort(st + 1,st + 1 + n * m);
    seat = (lower_bound(st + 1,st + 1 + n * m,R) - st);
    x = (seat - 1) / n + 1;
    if(x % 2 == 0)
    {
        y = n * x - seat + 1;
    }
    else
    {
        y = n + (seat - n * x);
    }
    cout << x << ' ' << y;
	return 0;
}
