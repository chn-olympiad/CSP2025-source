#include<bits/stdc++.h>
using namespace std;
string a;
int c[10000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> a;
    int i = 0,y = 1;
    while(a[i] != 0)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            c[y] = int(a[i] - '0');
            y++;
        }
        i++;
    }
    y--;
    sort(c+1,c+y+1);
    for(int j = y; j >= 1; j--)
    {
        cout << c[j];
    }
    return 0;
}
