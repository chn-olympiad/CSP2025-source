#include <bits/stdc++.h>
using namespace std;
bool cmp(int a , int b)
{
	return a >= b;
}
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m , a[110] = {};
    cin >> n >> m;
    for(int i = 1; i <= n*m ; i++)
    {
        cin >> a[i];
    }
    int p = a[1];
    sort(a+1 , a+n*m+1 , cmp);
    int i;
    for(i = 1 ; i <= n*m ;)
    {
        if(a[i] == p)
        {
            break;
        }
        i++;
    }
    int x , y = (i / n) + 1;
    if(i % n == 0) y = i / n;
    if(y % 2 == 1)
    {
        x = i % n;
        if(x == 0) x = n;
    }
    else
    {
        x = n + 1 - (i % n);
        if(i % n == 0) x = 1;
    }
    cout << y << " " << x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
