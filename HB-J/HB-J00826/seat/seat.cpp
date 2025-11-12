#include <bits/stdc++.h>
using namespace std;
int n,m,a[300][300],b[114514],cnt = 0,seat = 0,x,i = 1,j = 1,fang=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++)
    {
        cin >> b[i];
    }
    x = b[1];
    sort(b + 1,b + 1 + n * m,greater<int>());
    for(int i = 1;i <= n * m;i ++) {
        if(b[i] == x) {
            seat = i;
        }
    }
    while(cnt != seat) {
        //cout << i << ' ' << j << '\n';
        cnt ++;
        if(j == m || j == 0)
        {
            i ++;
            fang = fang * -1;
        }
        j += fang;
    }
    cout << i << ' ' << j;
    return 0;
}
