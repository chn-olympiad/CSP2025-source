#include<bits/stdc++.h>
using namespace std;
    int n,m;
    int t = 0;
    int cut = 1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out", "w",stdout);
    scanf("%d%d",&n,&m);
    int a[n*m+1];
    for(int i = 1; i <= n*m; i++)
        scanf("%d",&a[i]);
    t = a[1];
    for(int i = 1; i <= n*m; i++){
        for(int j = 1; j <= n*m-1; j++)
            if(a[j] < a[j+1]){
                int z = a[j];
                a[j] = a[j+1];
                a[j+1] = z;
            }
    }
    for(int i = 1; i <= n*m; i++){
        if(a[i] != t)
            cut++;
        else
            break;
    }
    if(cut <= n){
        printf("1 ");
        printf("%d",cut);
        return 0;
    }
    if(cut > n){
        if(cut % n == 0 && (cut / n) % 2 != 0){
            int js = cut / n;
            printf("%d ",js);
            printf("3");
        }
        if(cut % n == 0 && (cut / n) % 2 == 0){
            int os = cut / n;
            printf("%d ",os);
            printf("1");
        }
    }
return 0;
}
