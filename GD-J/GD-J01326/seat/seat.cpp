#include <bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,a[N*N],a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	int p=lower_bound(a+1,a+n*m+1,a1)-a;
	p=n*m-p+1;
	cout<<(p+n-1)/n<<' ';
	if(((p+n-1)/n)&1) cout<<(p-1)%n+1;
	else cout<<n-(p-1)%n;
	return 0;
}

