#include <bits/stdc++.h>
using namespace std;
int se,n,m,ans_n,ans_m,a[110],mark,loca;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    se = n*m;
    for(int i = 0; i < se; i++)
    {
        cin >> a[i];
    }
    mark = a[0];
    sort(a,a+se,greater<int>());
    loca = 0;
    for(int i = 0; i < se; i++)
    {
        if(a[i] == mark)
        {
            loca = i;
        }
    }
    if(loca < n) ans_m = 1;
    else ans_m = loca/n+1;
    if(ans_m % 2 == 1) ans_n = loca%n+1;
    else ans_n = n-(loca%n);
    cout << ans_m << " " << ans_n;
    cout << endl;
    return 0;
}