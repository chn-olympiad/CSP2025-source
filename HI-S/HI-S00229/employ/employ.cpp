#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n, m, s, p = 0, x = 0, c[n], i[n];
	cin >> n >> m >> s;
	for(int f = n - 1; f >= 0; f--){
		cin  >> c[f];
		i[ f - 1 ] += 1;
	}
		for(int j = n; j > 0; j--){
			if(s % 10 == 0){
				s /= 10;
				
			}else{
				x += 1;
				s /= 10;
			}
			if( x < m){
				p += 1;
			}
		}
	cout << p;
	return 0;
}
