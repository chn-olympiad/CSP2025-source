#include <bits/stdc++.h>
using namespace std;
int a[110];
int n,m,ran;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1)ran=x;
		a[x]++;
	}
	int id=0;
	for(int i=100;i>=1;i--){
		if(a[i])id++;
		if(i==ran)break;
	}
	if(id%n==0){
		cout<<(id/n)<<" ";
		if((id/n)%2==0)cout<<1;
		else cout<<n;
	}else{
		cout<<id/n+1<<" ";
		if((id/n+1)%2==0)cout<<n-(id%n)+1;
		else cout<<id%n;
	}
	
	return 0;
}