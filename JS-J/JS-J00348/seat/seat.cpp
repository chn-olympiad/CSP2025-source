#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    t = n * m;
    for (int i = 1;i <= t;i++) scanf("%d",a + i);
    int tmp = a[1];
    sort(a + 1,a + t + 1);
    int p = lower_bound(a + 1,a + t + 1,tmp) - a;
    p = t - p + 1;
    int x = (p + n - 1) / n,y = p % n;
    if (!y) y = n;
    if (x % 2 == 0) y = n - y + 1;
    printf("%d %d\n",x,y);   
    return 0;    
}