#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m = 0,n = 0;
    cin >> n >> m;
    int a[101] = {};
    for(int i = 0;i < n*m;i++)
    {
        cin >> a[i];
    }
    int R = a[0];
    int point = 0;
    sort(a,a + n * m);
    for(int i = n*m-1;i>=0;i--)
    {
        if(R == a[i])
        {
            point += 1;
            break;
        }
        point += 1;
    }
    int h = 0;
    h = (point-1) / m + 1;
    int l = 0;
    if(point % m == 0)
    {
        l = m * h;
    }
    else if(h % 2 == 0)
    {
        l = m + 1 - (point % m);
    }
    else{l = point % m;}
    cout << h << " " << l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
