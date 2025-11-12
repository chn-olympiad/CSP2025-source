#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n+1];
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=1,c=1;
	int cc=a[1];
	sort(a+1,a+n*m+1,cmp);
	int zx=0;
	for (int i=1;i<=n*m;i++){
		if (cc==a[i]) break;
		if (i%n==0) zx=1;
		if (zx==1){
			r++;
			zx=0;
		} else {
			if (r%2==1){
				c++;
			} else {
				c--;
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}
