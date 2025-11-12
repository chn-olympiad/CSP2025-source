#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int a[MAXN*MAXN];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int last;
    cin>>a[1];
    last = a[1];
    for (int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i] == last)
        {
            int t = i%n;
            int p;
            if (t == 0) t = n;
            if (t != n)
            {
                p = i/n+1;
            }
            else{
                p = i/n;
            }
            cout<<p<<" ";
            if (p%2 == 0)
            {
                cout<<n-t+1;
                break;
            }
            else
            {
                cout<<t;
                break;
            }
        }
    }
    return 0;
}
