#include<bits/stdc++.h>
using namespace std;
int n,m,p=0,c1,c,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c1;
	for(int i=2;i<=n*m;i++){
		cin>>c;
		if(c>c1) p++;
	}x=p/n+1;
	if(x%2==0) y=m-(p%n);
	else y=p%n+1;
	cout<<x<<" "<<y;
	return 0;
}
