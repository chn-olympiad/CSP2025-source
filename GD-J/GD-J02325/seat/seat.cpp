#include<bits/stdc++.h>
using namespace std;
int A,n,m,a[110],g[150][150];
bool cmp(int x,int y){
	return x>y;
}
void man(){
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++) cin >> a[i];
	A=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for (int i = 1;i<=n*m;i++){
		g[x][y]=a[i];
		if (y%2!=0){
			x++;
			if (x>n){
				x--;
				y++;
			}
		} else {
			x--;
			if (x<1){
				x++;
				y++;
			}
		}
	}
	for (int j = 1;j<=n;j++){
		for (int i = 1;i<=m;i++){
			if (g[i][j]==A){
				cout << j << " " << i;
				return;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	man();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
