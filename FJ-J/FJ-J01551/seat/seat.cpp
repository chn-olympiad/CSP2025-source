#include<bits/stdc++.h>
using namespace std;
long long n,m,b,c[105],x;
bool cmp(int a,int b) {
	return b<a;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>c[(i-1)*m+j];
			if(i==1&&j==1)b=c[(i-1)*m+j];
		}
	}
	sort(c+1,c+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(c[i]==b)x=i;
	}
	int v=x/(2*n);
	x%=2*n;
	if(x==0)x+=2*n;
	if(x<=n)printf("%d %d",2*v+1,x);
	else printf("%d %d",2*v+2,2*n-x+1);
	return 0;
}
