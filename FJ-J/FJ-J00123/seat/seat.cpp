#include<bits/stdc++.h>
using namespace std;
int a[400],b[20][20];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int gay;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
		if(i==1) gay=a[i];
	}
	if(m==1 && n==1) {
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,k=1;
	b[1][1]=a[1];
	while(k<=n*m) {
		while(x%2==1 && y+1<=m) {
			y++;
			k++;
			b[x][y]=a[k];
			if(a[k]==gay) break;
		}
		if(a[k]==gay) break;
		if(x%2==1 && y==m) {
			x++;
			k++;
			b[x][y]=a[k];
		}
		if(a[k]==gay) break;
		while(x%2==0 && y-1>=1) {
			y--;
			k++;
			b[x][y]=a[k];
			if(a[k]==gay) break;
		}
		if(a[k]==gay) break;
		if(x%2==0 && y==1) {
			x++;
			k++;
			b[x][y]=a[k];
		}
		if(a[k]==gay) break;
	}
	cout<<x<<" "<<y;
	return 0;
}
