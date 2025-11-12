#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    memset(a,0,sizeof(a));
    cin >> n >> m;

    int snm = n*m;
    for(int i = 1;i <= snm;i ++)
    {
        cin >> a[i];
    }

    int r = a[1];
    sort(a+1,a+1+snm,cmp);

    int place;
    for(int i = 1;i <= snm;i ++)
    {
        if(a[i] == r)
        {
            place = i;
            break;
        }
    }

    int lie = ceil(double(place) / double(n));
    int hang = place % n;
    if(hang == 0)hang = n;
    if(lie % 2 == 0)
    {
        hang = n - hang + 1;
    }
    cout << lie << ' ' << hang;
    return 0;
}
//ACACACACAC
//HXYHXYHXY
