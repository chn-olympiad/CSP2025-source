#include <bits/stdc++.h>
using namespace std;

int n,m,cnt = 0,a;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    int w;
    scanf("%d",&a);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (i || j){
                scanf("%d",&w);
                if (w > a)  cnt++;
            }
    int x,y;
    x = cnt/n + 1;
    if (x & 1)  y = cnt%n+1;
    else    y = n-cnt%n;
    printf("%d %d",x,y);
    return 0;
}
