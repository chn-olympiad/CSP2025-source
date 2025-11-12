#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
	int num;
	int id;
};
node a[1000005];
int b[105][105];
int cnt=0;
bool cmp(node t1,node t2) {
	return t1.num>t2.num;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2) {
			for(int j=1;j<=n;j++) {
				++cnt;
				b[j][i]=cnt;
			}
		}
		else {
			for(int j=n;j>=1;j--) {
				++cnt;
				b[j][i]=cnt;
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++) {
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int p=0;
	for(int i=1;i<=n*m;i++) {
		if(a[i].id==1) {
			p=i;
			break;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(b[i][j]==p) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
