#include<bits/stdc++.h>
using namespace std;
int zw[1000+10][1000+10];
int main() {
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,a[1000+10];
	//输入
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int r=a[1];
	//排序并判断小r的成绩
	sort(a+1,a+n*m+1);
	//排序
	int p=1;
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			zw[i][j]=a[p];
			if(a[p]==r) {
				cout<<i<<" "<<j<<endl;
			}
			p++;
			if(i==n) {
				j++;
				for(int i=n; i>=1; i--) {
					if(a[p]==r) {
						cout<<i<<" "<<j<<endl;
					}
					zw[i][j]=a[p];
					p++;
				}
			}
		}
	}
	return 0;
}
