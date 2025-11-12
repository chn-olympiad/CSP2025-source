#include<bits/stdc++.h>
using namespace std;
int t,n ;
int rest = 0 ;
int a[100005],b[100005],c[100005],m[100005];
int ans[10] ,ansj = 1;
int main(){
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    scanf("%d" ,&t) ;
    for(int times = 1 ; times <= t ; times++){
        memset(a,0,sizeof(a)) ;
        memset(b,0,sizeof(b)) ;
        memset(c,0,sizeof(c)) ;
        int am = -1 ,bm = -1 ,cm = -1 ;
        scanf("%d" ,&n) ;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d%d" ,&a[i] ,&b[i] ,&c[i]) ;
            am = max(a[i],am) ,bm = max(b[i],bm) ,cm = max(c[i],cm) ;
        }
        if(bm == 0 && cm == 0){
            for(int i = n ; i >= n/2 -1; i--){
                ans[ansj] += a[i] ;
                //printf("%d " ,ans[ansj]) ;
            }
        }
        else if(cm == 0){
            int g = 1 ;
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= n ; j++){
                    if(ans[ansj]<a[i]+b[j] && g<=n/2 && a[i]!=0 && b[j] !=0){
                        ans[ansj] = a[i]+b[j] ;
                        a[i] = 0 ;
                        b[j] = 0 ;
                        ++g ;
                    }
                    else if(a[i]!=0 && b[j]!=0){
                        i++ ;
                    }
                }
            }
        }
        else{
            int ge = 1 ;
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= n ; j++){
                    for(int rest = 1 ; rest <= n ; rest++){
                            //cout << i << " " << j << " " << rest << endl ;
                        if(ge<=n/2 && a[i]!=0 && b[j]!=0 && c[rest]!=0){
                            ans[ansj] = max(ans[ansj],a[j]+c[rest+1]) ;
                            ans[ansj] = max(ans[ansj],b[j+1]+c[rest]) ;
                            ans[ansj] = max(ans[ansj],a[i]+b[j+1]) ;
                            //cout <<a[i]+b[j]+c[rest] ;
                            //cout <<c[rest] ;
                            a[i] = 0 ,b[j] = 0 ,c[rest] = 0 ;
                            ++ge ;
                        }
                        else if(a[i]!=0 && b[j]!=0 && c[rest]!=0){
                            i++ ;
                        }
                    }
                }
           }
        }
    }
    for(int i = 1 ; i <= t ; i++){
        printf("%d " ,ans[i]) ;
    }
    /*for(int times = 1 ; times <= t ; times++){
        memset(a,0,sizeof(a)) ;
        memset(b,0,sizeof(b)) ;
        memset(c,0,sizeof(c)) ;
        int am = -1 ,bm = -1 ,cm = -1 ;
        scanf("%d" ,&n) ;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d%d" ,&a[i] ,&b[i] ,&c[i]) ;
            am = max(a[i],am) ,bm = max(b[i],bm) ,cm = max(c[i],cm) ;
        }
        if(bm == 0 && cm == 0){
            for(int i = n ; i >= n/2 -1; i--){
                ans[ansj] += a[i] ;
                //printf("%d " ,ans[ansj]) ;
            }
        }
        else if(cm == 0){
            int ca = 1 ;
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= n ; j++){
                    if(ans[ansj]<a[i]+b[j] && ca<=n/2 && a[i]!=0 && b[j] !=0){
                        ans[ansj] = a[i]+b[j] ;
                        a[i] = 0 ;
                        b[j] = 0 ;
                        ++ca ;
                    }
                }
            }
        }
        else{
            int ca = 1 ;
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= n ; i++){
                    for(int k = 1 ; k <= n ; k++){
                        if(ans[ansj] < a[i]+b[j]+c[k] && ca<=n/2 && a[i]!=0 && b[j]!=0 && c[k]!=0){
                            ans[ansj] = a[i]+b[j]+c[k] ;
                            a[i] = 0 ,b[j] = 0 ,c[k] = 0 ;
                            ++ca ;
                        }
                    }
                }
            }
        }
        ansj++ ;
    }
    for(int i = 1 ; i <= t ; i++){
        printf("%d " ,ans[i]) ;
    }*/
    return 0 ;
}//贪心：把每个人的最大值记录并分配到对应社团
