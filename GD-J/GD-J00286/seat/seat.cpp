#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,num,c,r,t=1;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> a[i];
	} 
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2==0) {
			for(int j=n;j>=1;j--) {
				if(a[t]==x) {
					c=i,r=j;
					cout << c << " " <<r;
					return 0;
				}
				t++;
			}
		}else{
			for(int j=1;j<=n;j++) {
				if(a[t]==x) {
					c=i,r=j;
					cout << c << " " <<r;
					return 0;
				}
				t++;
			}
		}
	}
	return 0;
} 
