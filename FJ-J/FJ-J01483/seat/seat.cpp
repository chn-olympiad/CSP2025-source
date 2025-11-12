#include<bits/stdc++.h>
using namespace std;
int n,m,a,p=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		if(a<b)p++;
	}
	cout<<p/n+((p%n)!=0)<<' ';
	if((p/n+((p%n)!=0))%2==1){
		if(p%n==0)cout<<n;
		else cout<<p%n;
	}
	else{
		if(p%n==0)cout<<1;
		else cout<<n+1-p%n;
	}

	return 0;
} 
