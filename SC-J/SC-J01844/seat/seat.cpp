#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],cj,pm;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			pm=n*m-i+1;
		}
	}
	int ps,ls;
	if(pm/n>=1&&pm%n==0){
		ls=pm/n;
		cout<<ls<<' ';
		if(ls%2==0) cout<<1;
		else cout<<n;
	}
	else{
		ls=pm/n+1;
		cout<<ls<<' ';
		if(ls%2==0) cout<<n-pm%n+1;
		else cout<<pm%n;
	}
	return 0;
}