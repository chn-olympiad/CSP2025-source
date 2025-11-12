#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],R,x[101],y[101],p=1;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;) {
		for(int j=1;j<=m;j++) {
			x[a[p]]=i;
			y[a[p]]=j;
			p++;
		}
		i++;
		if(i>m) break;
		for(int j=m;j>=1;j--) {
			x[a[p]]=i;
			y[a[p]]=j;
			p++;
		}
		i++;
	}
	cout<<x[R]<<" "<<y[R]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
