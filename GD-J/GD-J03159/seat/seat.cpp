#include <bits/stdc++.h>
using namespace std;
int a[102],dis[12][12];
int n,m;
int sum,ans = 1;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
		if(i == 1) sum = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int k = 1;
	for(int i = 1;i <= m;i++){
		if(k == 1){
			for(int j = 1;j <= n;j++){
				dis[i][j] = a[ans];
				if(a[ans] == sum){
					cout << i << " " << j;
					return 0;
				} 
				ans++;
			}	
			k = 0;
		}
		else{
			for(int j = n;j >= 1;j--){
				dis[i][j] = a[ans];
				if(a[ans] == sum){
					cout << i << " " << j;
					return 0;
				} 
				ans++;
			}
			k = 1;
		}
	}
	return 0;
}
