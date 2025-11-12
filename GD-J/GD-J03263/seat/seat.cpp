#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,t,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)t++;
	}
	x=(t/n)+1;
	if(t%(2*n)<=n-1)y=t%n+1;
	else y=2*n-t%(2*n);
	cout<<x<<" "<<y;	
	return 0;
}
 
