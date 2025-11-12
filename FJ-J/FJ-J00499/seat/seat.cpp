#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],k,l,ansx,ansy;
bool cmp(int p,int q) {
	return p>q;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1; i<=n*m; i++)cin>>a[i];
	k = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i = 1; i<=n*m; i++) {
		if(a[i]==k) {
			l = i;
			break;
		}
	}
	ansy = (l+n-1)/n;
	ansx = (l-1)%n+1;
	if(ansy%2==0)ansx = n+1-ansx;
	cout<<ansy<<" "<<ansx<<"\n";
}
