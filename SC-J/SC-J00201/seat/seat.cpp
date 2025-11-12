#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x,num=0;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		int f;
		cin>>f;
		if(x>f) num+=1;
		
	}
	num+=1;

	int e=num/n;
	
	
	int f;
	if(num==e*n) {
		cout<<e<<" ";
		if(e%2==0) cout<<1;
		else cout<<2;
		return 0;
	}
	e+=1;
	if(e%2==1)f=num-(e-1)*n;
	else f=n+1-(num-(e-1)*n);
	cout<<e<<" "<<f;
	return 0;
}