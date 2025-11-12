#include <bits/stdc++.h>
using namespace std;
const int MAXNM=1e3+3;
int a[MAXNM],n,m,key;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	key=a[1];
	sort(a+1,a+n*m+1);
	int keyid=n*m-(lower_bound(a+1,a+n*m+1,key)-a)+1;
	int y=(keyid%n==0 ?keyid/n:keyid/n+1);
	int x=(y%2==1 ?(keyid-1)%n+1:n-(keyid-1)%n);
	cout<<y<<" "<<x;
	return 0;
}
