#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N=205;
int n,m,a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int now=a[1];
	int pos=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1; i<=n*m; i++) {
		if(a[i]==now) {
			pos=i;
			break;
		}
	}
	pos-=1;
	int mod=pos%n;
	int cnt=pos/n;
	if(cnt%2==0) {
		cout<<cnt+1<<" "<<mod+1;
	} else {
		cout<<cnt+1<<" "<<n-mod;
	}
	return 0;
}
