#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=1;
	for(int i=1; i<=n*m; ++i) {
		scanf("%d",&a[i]);
		if(a[i] > a[1])++cnt;
	}
	int c,r;
	c=cnt/n;
	r=cnt%n;
	if(r != 0) {
		++c;
		if(c%2 == 0) {
			r=n-r+1;
		}
	} else r=n;
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}