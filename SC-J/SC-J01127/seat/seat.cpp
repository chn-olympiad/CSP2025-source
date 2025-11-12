#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int n,m,a[maxn],b,cnt;
int ans[11][11];

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1; i<=sum; ++i) {
		cin>>a[i];
		if(i==1) b=a[i];
	}
	sort(a+1,a+sum+1,cmp);
	for(int y=1; y<=m; ++y) {
		if(y%2==1) {
			for(int x=1; x<=n; ++x) {
				ans[x][y]=a[++cnt];
				if(a[cnt]==b) {
					cout<<y<<' '<<x;
					return 0;
				}
			}
		}
		if(y%2==0) {
			for(int x=n; x>=1; --x) {
				ans[x][y]=a[++cnt];
				if(a[cnt]==b) {
					cout<<y<<' '<<x;
					return 0;
				}
			}
		}
	}
	return 0;
}