#include<bits/stdc++.h>
using namespace std;

int n,m,a[120],r;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n * m;i++)
            scanf("%d",&a[i]);
    r = a[1];
    sort(a + 1,a + n * m + 1);
    int i = 0,j = 1;
    bool b = 0;
    for (int k = n * m;k >= 1;k--){
        if (b == 0){
            i++;
            if (i > n){
                j++;
                i = n;
                b = 1;
            }
        }
        else{
            i--;
            if (i < 1){
                j++;
                i = 1;
                b = 0;
            }
        }
        if (a[k] == r){
            printf("%d %d",j,i);
            return 0;
        }
    }
    return 0;
}
