#include <cstdio>
#include <algorithm>
using std::swap ;
using std::max ;
using std::min ; 

int t , n , sum ;
int a[100721][4] , st[100721] ;

int main(void){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	scanf("%d" , &t) ;
	while(t --){
		scanf("%d" , &n) ;
		int m = n / 2 ;
		sum = 0 ;
		int s1 = m , s2 = m , s3 = m ;
		int c[4] , mxp , sep ;
		for(int i = 0 ; i < n ; i ++){
			scanf("%d %d %d" , &a[i][1] , &a[i][2] , &a[i][3]) ;
			c[1] += a[i][1] , c[2] += a[i][2] , c[3] += a[i][3] ;
		}
		for(int i = 0 ; i < n ; i ++){
			if(a[i][1] == max(a[i][1] , max(a[i][2] , a[i][3]))){
				mxp = 1 ;
				if(a[i][2] >= a[i][3])  sep = 2 ;
				else  sep = 3 ;
			}
			else if(a[i][2] == max(a[i][1] , max(a[i][2] , a[i][3]))){
				mxp = 2 ;
				if(a[i][1] >= a[i][3])  sep = 1 ;
				else  sep = 3 ;
			}
			else{
				mxp = 3 ;
				if(a[i][1] >= a[i][2])  sep = 1 ;
				else  sep = 2 ;
			}
			
			if((c[mxp] - a[i][mxp]) >= a[i][sep]){
				sum += a[i][mxp] ;
				c[mxp] -= a[i][mxp] ;
				continue ;
			}
			else{
				if(c[sep] - a[i][sep] >= a[i][6 - mxp - sep]){
					sum += a[i][sep] ;
					c[sep] -= a[i][sep] ;
					continue ;
				}
				else{
					sum += a[i][6 - mxp - sep] ;
					c[6 - mxp - sep] -= a[i][6 - mxp - sep] ;
				}
			}
		}
		printf("%d\n" , sum) ;
	}
}

//  :(

