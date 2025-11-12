#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,cnt = 1,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++) scanf("%d",&a[i]);
    for(int i = 2;i <= n * m;i++)
        if(a[i] > a[1]) cnt++;
    x = cnt / n,cnt %= n;
    if(cnt) x++;
    else cnt = n;
    if(x % 2) y = cnt;
    else y = n - cnt + 1;
    cout << x << " " << y;
    return 0;
}
// fc 文件1 文件2
