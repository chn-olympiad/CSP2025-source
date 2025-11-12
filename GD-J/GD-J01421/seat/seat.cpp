#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans,zzy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	cin>>zzy;
	for(int i=2;i<=k;i++){
		int q;
		cin>>q;
		if(q>zzy) ans++;
	}
	ans++;
	x=(ans-1)/n+1;
	y=(ans-1)%n+1;
	cout<<x<<' '; 
	if(x%2==1) {
		cout<<y;
	}
	else{
		cout<<n-y+1;
	}
	return 0;
}
