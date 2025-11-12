#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a < b;}
int n,m,a[110],s,nm;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n * m;i++)
    {
        cin >> a[i];
    }
    s = a[1];
    sort(a,a + (n * m),cmp);
    for (int i = 0 ;i < n * m;i++)
    {
        if (s == a[i])
        {
            nm = i;
            break;
        }
    }
    int c = (nm / n) + 1,r = (nm % n);
    cout << r << " " << c;
    return 0;
}
