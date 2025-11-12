#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	int n,m,a[11],map[11][11];
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i =0 ;i < n*m;i++){
		cin >> a[i];
	}	
	int ans = a[0];
	sort(a,a+n*m,cmp);
	int t=0;
	for(int i = 1;i <= m+1;i += 2){
		for(int j = 1;j <= n;j++){
			map[i][j] = a[t++];
			if(map[i][j] == ans){
				cout << i-1<< " " << j;
			return 0; 
			}
		} 
		i++;
		for(int j = n;j >= 1;j--){
			map[i][j] = a[t++];	
			if(map[i][j] == ans){
				cout << i << " " << j;
			return 0; 
			}
		}	
	}
}
