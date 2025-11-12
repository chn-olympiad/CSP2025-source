#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int t;
    cin >> t;
    a[0]=t;
    for (int i=1;i<m*n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n*m,cmp);
    for (int i=0;i<m*n;i++)
    {
        if (a[i]==t)
        {
            cout << i/n+1 << ' ';
            if ((i/n)%2==0)
            {
                cout << i%n+1;
            }
            else
            {
                cout << n-i%n;
            }
            break;
        }
    }
}
