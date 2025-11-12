#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++)
        scanf("%d",&a[i]);
    x = a[1];
    sort(a + 1,a + n * m + 1);
    int i = 1,j = 0,k = 0;
    for(int l = n * m;l >= 1;l--){
        if(i % 2 && j == n)
            i++,l++;
        else if(i % 2 == 0 && j == 1)
            i++,l++;
        if(a[k] == x){
            printf("%d %d",i,j);
            return 0;
        }
        if(i % 2 == 1)
            j++;
        else
            j--;
        if(a[l] == x){
            printf("%d %d",i,j);
            return 0;
        }
    }
}
