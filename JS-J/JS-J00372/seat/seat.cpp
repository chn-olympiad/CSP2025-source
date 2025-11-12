#include <bits/stdc++.h>
using namespace std;
int n,m,r,sum,x;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> r;
    for(int i=2;i<=n*m;i++)
    {
        cin >> x;
        if(x>r)
        {
            sum=sum+1;
        }
    }
    int c,r;//0 3 4
            //1 2 5
    cout << sum/n+1 << ' ';
    if(sum%(2*n)<n)
    {
        cout << (sum%n)+1;
    }
    else
    {
        cout << n-(sum%n);
    }
}
