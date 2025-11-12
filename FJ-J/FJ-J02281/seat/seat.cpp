#include <bits/stdc++.h>
using namespace std; 

int n,m,at;
int a[105];
int ansx,ansy;

void dfs() {
	int x = 1,y = 1,num = n * m;
	while(1) {
		if(a[num] == at) {
			ansx = x;
			ansy = y;
			return ;
		}
		if(y % 2 == 0) {
			if(x == 1) y++;
			else x--;
		} else {
			if(x == n) y++;
			else x++; 
		}
		num--;
	}
} 


int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++) {
		scanf("%d",&a[i]);
		if(i == 1) at = a[i];
	}
	sort(a + 1,a + n * m + 1);
	dfs();
	printf("%d %d",ansy,ansx);
}
