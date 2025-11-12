#include <bits/stdc++.h>
using namespace std;
struct node{
	int d, val;
	bool operator < (const node &o) const{
		return val>o.val;
	}
}a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n*m; i++){
		scanf("%d", &a[i].val); 
		a[i].d=i;
	}
	sort(a+1, a+1+n*m);
	int x=1, y=0, way=1;
	for(int i=1; i<=n*m; i++){
		if(way==0){
			y--;
		}else{
			y++;
		}
		if(y>n){
			y--;
			x++;
			way=0;
		}else if(y<1){
			y++;
			x++;
			way=1;
		}
		if(a[i].d==1){
			printf("%d %d", x, y);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
