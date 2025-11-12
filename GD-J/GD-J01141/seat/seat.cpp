#include<bits/stdc++.h>
using namespace std;
int n , m ;
int mp[110][110];
bool cmp(int x , int y){
	return x < y ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	int a[220] ;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i] ;
	}
	int x ;
	int y ;
	int ans = a[1] ;
	int i , j ;
	sort(a+1,a+n+1,cmp);
	if(m%2 == 0){
		int num = 1 ;
		for(i = 1;i <= m/2;i++){
			for(j = 1;j <= n*2;j++){
				mp[i][j] = a[num++];
				if(mp[i][j] == ans){
					x = i ;
					y = j ;
				}
			}
		}
	}else if(m%2 == 1){
		int num = 1 ;
		for(i = 1;i <= m/2;i++){
			for(j = 1;j <= n*2;j++){
				mp[i][j] = a[num++];
				if(mp[i][j] == ans){
					x = i ;
					y = j ;
				}
			}
		}
		for(int g = 1;g <= n;g++){
			mp[i][g] = a[num++] ;
		}
	}
	cout << i << j ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
