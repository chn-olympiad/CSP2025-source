#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+n*m,greater<int>());
	int pos;
	for(int i=0; i<n*m; i++) {
		if(a[i]==x) {
			pos=i+1;
		}
	}
	int res;
	if(pos%n==0) {
		res=pos/n;
	} else {
		res=pos/n+1;
	}
	cout<<res<<" ";
	if(res&1) {
		cout<<(pos-1)%n+1;
	} else {
		cout<<n+1-((pos-1)%n+1);
	}
	return 0;
}
