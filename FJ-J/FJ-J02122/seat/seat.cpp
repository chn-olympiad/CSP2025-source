#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int b[105][105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int k = a[1];
	sort(a+1,a+n*m+1,cmp);
	int x = 1,y = 1,l = 0;
	while(x <= n && y <= m){
		for(int x = 1;x <= n;x++){
			b[x][y] = a[++l];
			if(b[x][y] == k){
				cout << y << " " << x;
				return 0;
			}
		}
		y++;
		for(int x = n;x >= 1;x--){
			b[x][y] = a[++l];
			if(b[x][y] == k){
				cout << y << " " << x;
				return 0;
			}
		}
		y++;
	}
	return 0;
} 
