//GZ-S00117 贵阳市第十九中学 唐靖越
#include<bits/stdc++.h>
using namespace std ;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n , t , a1 = 0 , a2 = 0 , a3 = 0 , m , m1 = 0 , ai=1 , bi=1 , ci=1 ;
	int a[10000000][150];
	int a4[1500000] ;
	cin >> t ;
	for(int q = 1 ; q <= t ; q++) {
		cin >> n ;
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i][1] ;
			cin >> a[i][2] ;
			cin >> a[i][3] ;
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				a1++;
				a4[ai] = a[i][1] ;
				ai++;
				m1 += a[i][1] ;
			} 
			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				a2++;
				m1 += a[i][2] ;
			} 
			else {
				a3++;
				m1 += a[i][3] ;
			}
		}
		sort(a4+1,a4+1+n);
		while(true){
			if(a1 > n / 2){
				for(int i = 1 ; i <= n ; i++) {
					if(a[i][2] >= a[i][3]){
						m1 -= a[i][1] ;
						m1 += a[i][2] ;
						a1 -- ;
					}
					else if(a[i][2] < a[i][3]){
						m1 -= a[i][1] ;
						m1 += a[i][3] ;
						a1 -- ;
					}
				}
			}
			else{
				break ;
			}			
		}
		cout << m1 << endl ;
		m1 = 0 ;
	}
	return 0 ;
}

