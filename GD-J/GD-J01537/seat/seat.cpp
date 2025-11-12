#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], a1, l, s[15][15], x, y;
bool cmp(int a1, int a2) { return a1>a2; }
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	a1=55;
	sort(a+1, a+n*m+1, cmp);
	for(int i=1; i<=m; i++){
		if(i&1){
			for(int j=1; j<=n; j++){
				s[j][i]=a[++l];
				if(a[l]==a1) x=i, y=j;
			}
		}
		else{
			for(int j=n; j>=1; j--){
				s[j][i]=a[++l];
				if(a[l]==a1) x=i, y=j;
			}
		}
	}
	cout << x << ' ' << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
