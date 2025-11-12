#include <bits/stdc++.h>
// #include <dragonpro.h>
// #define ll long long
// #define pr pair<,>
using namespace std;
int a[110];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n , m , cnt = 1; 
    cin >> n >> m >> a[1];
    for(int i = 2 ; i <= n * m ; i ++)
    {
        cin >> a[i];
        if(a[i] > a[1]) cnt ++;
    }
    int x = (cnt - 1) / n + 1 , y;
    if(x % 2 == 0) y = n - ((cnt + n - 1) % n + 1) + 1;
    else y = (cnt + n - 1) % n + 1;
    cout << x << " " << y << endl;
	return 0;
}
// dragonpro-presents
