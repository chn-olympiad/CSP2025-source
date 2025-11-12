#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	}
	b=x/n+1;
	if(x%n==0)
		b--;
	if(b%2==0)
		if(x%n==0)
			c=1;
		else
			c=n-(x%n)+1;
	else
		if(x%n==0)
			c=n;
		else
			c=x%n;
	cout<<b<<' '<<c;
	return 0;
}
