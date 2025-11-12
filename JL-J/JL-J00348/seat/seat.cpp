#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a > b;
}
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,t = 0;
    cin >> m >> n;
    for(int i = 0;i < m*n;i++)
        cin >> a[i];
    int s = a[0];
    sort(a,a + n*m - 1,cmp);
    while(1)
    {
        if(a[t] == s)
        {
            t++;
            if(t <= m)
            {
                cout << (t-t%m)/m << ' ';
                int q = (t-t%m)/m;
                if(q%2 == 1)
                {
                    if(t == m)  cout << t;
                    else    cout << t%m;
                }
                else    cout << n-t%m;
            }
            else
            {
                cout << (t-t%m)/m+1 <<' ';
                int q = (t-t%m)/m;
                if(q%2 == 1)    cout << t%m+1;
                else    cout << n-t%m+1;
            }
            return 0;
        }
        t++;
    }
}
