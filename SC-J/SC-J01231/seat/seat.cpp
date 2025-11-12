#include<bits/stdc++.h>
using namespace std;
int n,m,b=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m-1];
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m-1;i++){
		if(a[i]>a[0]) b++;
	}
	c=1+((b-1)/n);
	if(c%2==1) r=1+((b-1)%n);
	else r=n-((b-1)%n);
	cout<<c<<' '<<r;
	return 0;
}
