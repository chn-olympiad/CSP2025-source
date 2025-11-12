#include <bits/stdc++.h>
using namespace std;
int n,m,a[114514],b[114514],c,x = 1,y = 1,maxn;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++) cin >> a[i];
	for(int i = 1 ; i <= n * m ; i++){
		maxn = -114;
		for(int j = 1 ; j <= n * m ; j++) if(b[j] == 0 && a[j] > maxn) maxn = a[j],c = j;
		b[c] = i;
	}
	for(int i = 2 ; i <= b[1] ; i++){
		if(x + 1 <= n && y % 2 == 1) x++;
		else if(x - 1 >= 1 && y % 2 == 0) x--;
		else y++;
	}
	cout << y << " " << x << endl;
	return 0;
}
