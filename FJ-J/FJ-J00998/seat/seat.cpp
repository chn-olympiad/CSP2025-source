#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	for(int i=1; i<=m*n; i++) {
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==k) l=m*n-i+1;
	}
	int c;
	if(l%n==0) c=l/n;
	else c=l/n+1;
	cout<<l<<" ";
	if(c%2==1) cout<<n-c+1;
	else cout<<c;
	return 0;
}
