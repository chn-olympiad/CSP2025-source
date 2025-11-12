#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],r,t;
bool gz(long long x,long long y) {
	return x>y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,gz);
	for(long long i=1;i<=n*m;i++) {
		if(a[i]==r) {
			t=i;
			break;
		}
	}
	cout<<(t-1)/n+1<<" ";
	if(((t-1)/n+1)%2==0) cout<<n-(t%n)+1;
	else if(t%n!=0) cout<<t%n;
	else cout<<n;
	return 0;
}