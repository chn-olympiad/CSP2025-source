#include<bits/stdc++.h>
using namespace std;
int a[150],t;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	int x=lower_bound(a+1,a+1+m*n,t)-a;
	x=m*n-x+1;
	if(x%n==0) {
		cout<<x/n<<" ";
		if((x/n)%2==0) cout<<1;
		else cout<<n;
	}
	else {
		cout<<x/n+1<<" ";
		if((x/n+1)%2==0) cout<<n-x%n+1;
		else cout<<x%n;
	}
		
	

	return 0;
}
