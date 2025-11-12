#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;//R's point
int g;//R's grade
//x = ceil(g/n)
//y = g%n
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    int a;//other's
    g = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&a);
            if(i == 1 && j == 1){
                    s = a;
                   // printf("111");
            }
            g += (a > s ? 1:0);
           // printf("%d %d   %d\n",a,s,g);
        }
    }
    if(g % n == 0){
        printf("%d %d",g/n,((g/n)%2 == 0) ? 1 : n);
    }
    else{
        int aa = g/n+1;
        printf("%d ",aa);
        if(!aa % 2){
            printf("%d",(g - g/n)%n);
        }
        else printf("%d",n - ((g - g/n)%n));
    }
	return 0;
}
