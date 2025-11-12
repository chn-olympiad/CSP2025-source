#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pm;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	int rcj=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(a[i]==rcj) pm=i+1;
	}
	if(pm%n==0){
		cout<<pm/n<<" ";
		if(pm%n!=0){
			if((pm/n)%2!=0) cout<<pm%n;
			if((pm/n)%2==0) cout<<n+1-pm%n;}
		if(pm%n==0){
			if((pm/n)%2!=0) cout<<n;
			if((pm/n)%2==0) cout<<1;}
	}else {
		cout<<pm/n+1<<" ";
		if(pm%n!=0){
			if((pm/n+1)%2!=0) cout<<pm%n;
			if((pm/n+1)%2==0) cout<<n+1-pm%n;}
		if(pm%n==0){
			if((pm/n+1)%2!=0) cout<<n;
			if((pm/n+1)%2==0) cout<<1;}
	}
	return 0;
}
