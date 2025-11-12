#include<bits/stdc++.h>
using namespace std;
int s[105];
int sit[105][105];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int num;
	int n , m;
	cin >> n >> m;
	cin >> num;
	s[1] = num;
	for(int i = 2 ; i <= n * m ; i++) cin >> s[i];
	sort(s+1,s+n*m+1,cmp);
	int x = 0 , i , cnt = 0;
	while(x < m){
		x++;
		if(x % 2 != 0){
			for(i = 1 ; i <= n ; i++){
				cnt++;
				sit[i][x] = s[cnt];
			} 
		}
		else{
			for(i = n ; i >= 1 ; i--){
				cnt++;
				sit[i][x] = s[cnt];
			}
		}
	}
	for(i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(sit[i][j] == num) cout << j << " " << i;
		}
	}
	return 0;
}
