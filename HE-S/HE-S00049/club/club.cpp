#include <bits/stdc++.h>
using namespace std ;
long long a , b , s[1000000][1000000];
long long x=0,y=0,z=0,m=0,n=0,k=0;
int main (){
	cin >> a ;
	for(int i=1;i <= a ; ++i) {
		cin >> b ;
		for(int j = 1;j <= b ; ++j) {
			cin >> s[j][2] ;
			cin >> s[j][2] ;
			cin >> s[j][3] ;
		}
		for(int j = 1 ; j <=b ; ++j ){
			if(s[j][1] >= s[j][2]){
				if(s[j][1] > s[j][3]){
					if(x/2>a){
						if(s[j][2] >= s[j][3]){
							y++;
							n = n + s[j][2];
						}
						else{
							z++;
							k = k + s[j][3];
						}
					}else{
						x++;
						m = m + s[j][1];
					}
				}
			}
			if(s[j][2] >= s[j][1]){
				if(s[j][2] > s[j][3]){
					if(y/2>a){
						if(s[j][1] >= s[j][3]){
							x++;
							m = m + s[j][1];
						}
						else{
							z++;
							k = k + s[j][3];
						}
					}else{
						y++;
						n = n + s[j][2];
					}
				}
			}
			if(s[j][3] >= s[j][1]){
				if(s[j][3] > s[j][2]){
					if(z/2>a){
						if(s[j][2] >= s[j][1]){
							y++;
							n = n + s[j][2];
						}
						else{
							x++;
							m = m + s[j][1];
						}
					}else{
						z++;
						k = k + s[j][3];
					}
				}
			}
			cout << m+n+k << endl;

		}

	}


	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	return 0 ;
}
