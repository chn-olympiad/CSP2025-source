#include <bits/stdc++.h>
using namespace std;
int a[1000],n,cnt = 0,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)cin>>a[i];
    for(int i = 2;i <= n*m;i++)
    {
        if(a[i] > a[1])cnt++;
    }
    cout << 1 + cnt/n << ' ';
    if((1+cnt/n) % 2 == 0)
    {
        cout << n-(cnt%n);
    }
    else{
        cout << 1 + cnt % n;
    }
    return 0;
}
