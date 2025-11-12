#include<bits/stdc++.h>
using namespace std;
int n,m,tgt;
int a[1000005],b[1005][1005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	tgt=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=m&&!flag;i++) {
		if(i&1) {
			for(int j=1;j<=n;j++) {
				b[i][j]=a[++cnt];
				if(b[i][j]==tgt) {
					cout<<i<<" "<<j;
					flag=1;
					break;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--) {
				b[i][j]=a[++cnt];
				if(b[i][j]==tgt) {
					cout<<i<<' '<<j;
					flag=1;
					break;
				}
			}
		}
	}
	return 0;
}
