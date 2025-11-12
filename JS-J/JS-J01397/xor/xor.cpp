#include <bits/stdc++.h>
using namespace std ;
int a[1000001] ;
int main(){
    freopen("xor.in","r",stdin) ;
    freopen("xor.out","w",stdout) ;
    int n,k ;
    scanf("%d%d",&n,&k) ;

    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]) ;
    }
    if(k == 0){
        printf("1") ;
        return 0 ;
    }
    int ans = -1 ;
    for(int i = 1; i <= n; i++){
        int res = a[i] ;
        int sum =0 ;
        for(int j = i; j <= n; j++){
                if(res == k){
                    sum++ ;
                    if(j + 1 <= n){
                        res = a[j+1] ;
                    }
                }else{
                    res^= a[j] ;
                }



        }
        ans = max(sum,ans) ;
    }
    printf("%d",ans) ;
    return 0;
}
