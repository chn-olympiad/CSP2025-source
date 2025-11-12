#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,x=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		x++;
		if(a[i]==l) break;
	}
	x=n*m-x+1;
	if(x%n==0) cout<<x/n<<" ";
	else cout<<x/n+1<<" ";
	if(x%(n*2)<=n) cout<<x%(n*2);
	else cout<<x%(n*2)-x+n;
	return 0;
}