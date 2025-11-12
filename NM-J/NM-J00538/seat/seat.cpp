#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;++i)
        scanf("%d",&a[i]);
    int x = a[1];
    sort(a + 1,a + n * m + 1,greater<int>());
    int p = 0;
    for(int i = 1;i <= n * m;++i)
        if(a[i] == x){
            p = i;
            break;
        }
    int c = (p + n - 1) / n,r = 0;
    if((p + n - 1) / n % 2){
        if(p % n == 0)
            r = n;
        else
            r = p % n;
    }else{
        if(p % n == 0)
            r = 1;
        else
            r = n - p % n + 1;
    }
    printf("%d %d\n",c,r);
    return 0;
}
