#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],min1 = 1e9,xx = 1,yy = 1,b[1005][1005];
bool d(int x,int y){
	return x > y;
}
queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
		min1 = min(min1,a[i]);
		q.push(a[i]);
	}
	int c = a[1];
	if(a[1] == min1){
		cout<<1<<" "<<m;
		return 0;
	}
	sort(a+1,a+n*m+1,d);
	for(int i = 1;i <= n*m;i++){
		q.push(a[i]);
	}
	for(int i = 1;i <= n*m;i++){
		q.pop();
	}
	while(q.size() != 0){
		b[xx][yy] = q.front();
		q.pop();
		if(xx%2 == 1){
			yy++;
		}else{
			yy--;
		}
		if(yy > n||yy < 1){
			xx++;
			if(xx%2 == 1){
				yy++;
			}else{
				yy--;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == c){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
