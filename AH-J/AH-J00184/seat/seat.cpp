#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,y,z; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	z=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==z){
			z=(n*m)-i+1;
			break;
		}
	}
	if(z%n==0){
		x=z/n;
		if(x%2==0)y=1;
		else y=n;
	}else {
		x=z/n+1;
		if(x%2==1)y=z%n;
		else y=n-(z%n)+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
