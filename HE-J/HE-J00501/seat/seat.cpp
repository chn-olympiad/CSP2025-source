#include <bits/stdc++.h>
using namespace std;
int w[100005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int e = n*m;
    for (int i =1 ;i <= e;i++)
        cin >> w[i];
    int a = w[1],q;
    sort(w+1,w+e+1);
    for (int i = 1;i <= e;i++)
    {
        if(w[i] == a)
        {
            q = e-i+1;
        }
    }
    if (q % n == 0)
    {
        if ((q/n)-1 % 2 == 0)
            cout << q/n << " " << n;
        else
            cout << q/n << " " << 1;
        return 0;
    }
    if ((q/n)%2 == 0)
    {
        cout << (q/n)+1 << " " << q%n;
    }
    else
        cout << (q/n)+1 << " " << m-q%n+1;
    return 0;
}
