#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int rf=a[1];
	sort(a+1,a+n*m+1,cmp);

	int id=1;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==rf) {
			id=i;
			break;
		}
	}
	int l=(id+n-1)/n;
	int h=id%m;
	if(l%2==1) {
		if(h==0)h=m;
		cout<<l<<" "<<h;
	} else {
		if(h==0)h=m;
		cout<<l<<" "<<n-h+1;
	}

	return 0;
}

