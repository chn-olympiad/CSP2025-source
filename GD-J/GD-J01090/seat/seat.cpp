#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) {
		cin>>a[i];
	}
	int k=a[1],id=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i) {
		if(a[i]==k) id=i;
	}
	int x=1,y=1,cnt=1;
	while(cnt!=id) {
		cnt++;
		if(y%2!=0) {
			x++;
			if(x>n) {
				x=n;
				y++;
			}
			continue;
		}
		if(y%2==0) {
			x--;
			if(x==0) {
				x=1;
				y++;
			}
			continue;
		}
	}
	cout<<y<<" "<<x;
}
