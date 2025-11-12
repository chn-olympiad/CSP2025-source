//seat
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k,p=1,ansi,ansj;
	cin>>n>>m;
	cin>>k;
	for(int i=2; i<=n*m; i++){
		long long x;
		scanf("%lld", &x);
		if(x>k) p++;
	}
	ansj=ceil(p*1.0/n);
	if(ansj%2==0){
		if(p%n==0) ansi=1;
		else ansi=n-p%n+1;
	}
	else{
		ansi=p%n;
		if(ansi==0) ansi=n;
	}
	cout<<ansj<<" "<<ansi;
	return 0;
}
