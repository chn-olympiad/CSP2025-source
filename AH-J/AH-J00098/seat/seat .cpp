#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],n,m;
int main(){
	freopen("seat.in"."r".stdin);
	freopen("seat.out"."w".stdout);
	int  n,m;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++) cin>>a[i];
	int b=a[0];
	sort (a,a+n*m,greater<int>());
	int i;
	i=lower_bound(b,a,a+n*m);
	int c;
	c=i/n+1,r;
	else r=n-i%n;
	cout<<i<<" ";
 	
	
	
	
	return 0;
}
