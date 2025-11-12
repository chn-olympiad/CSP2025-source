#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9 ;
int t , n;
int a[N],b[N],c[N] ;
int dp[209][209][209] ;
struct node{
    int a,b;
}num[N];

bool cmp(node a,node b){
    int x1 = abs(a.a-a.b);
    int y1 = abs(b.a-b.b);
    return x1 > y1 ;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t ;
    while(t--){
        cin >> n ;
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i ++ ){
            cin >> a[i] >> b[i] >> c[i] ;
        }
        if( n > 205 ){
            for(int i = 1 ; i <= n ; i ++ ){
                num[i].a = a[i] ;
                num[i].b = b[i] ;
            }
            sort(num+1,num+n+1,cmp);
            int cnt_a = 0 ,cnt_b = 0;
            for(int i = 1 ; i <= n ; i ++ ){
                if(num[i].a > num[i].b ){
                    if(cnt_a < n/2){
                        ans += num[i].a ;
                        cnt_a ++ ;
                    }
                    else{
                        ans +=num[i].b ;
                        cnt_b ++ ;
                    }

                }
                else{
                    if(cnt_b < n/2){
                        ans += num[i].b ;
                        cnt_b ++ ;
                    }
                    else{
                        ans +=num[i].a ;
                        cnt_a ++ ;
                    }
                }
            }
            cout << ans << endl ;
            return 0 ;
        }
        ans = 0 ;
        dp[0][0][0] = 0;
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 0 ; j <= i ; j ++ ){
                for(int k = 0; j + k <= i ; k ++ ){
                    if(j > n/2 || k > n/2 || (i - j - k) > n/2 )
                        continue ;
                    int p_a = dp[i-1][j-1][k] + a[i];
                    int p_b = dp[i-1][j][k-1]+ b[i] ;
                    int p_c = dp[i-1][j][k] + c[i] ;
                    if(j == 0) p_a = -1 ;
                    if(k == 0) p_b = -1 ;
                    if(i-j-k == 0) p_c = -1 ;
                    dp[i][j][k] = p_a ;
                    dp[i][j][k] = max( dp[i][j][k] , p_b );
                    dp[i][j][k] = max( dp[i][j][k] , p_c );
                    ans = max( dp[i][j][k] , ans ) ;
                }
            }
        }
        cout << ans << endl;
    }
    return 0 ;
}
// I LOVE HXT !
