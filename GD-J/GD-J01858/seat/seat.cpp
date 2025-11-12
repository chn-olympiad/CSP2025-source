#include <bits/stdc++.h>
using namespace std;
int const N = 20;
int n,m,a,x ,rk=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	
	for(int i =2 ;i<=n*m;i++){
		cin>>x;
		if(x>a)rk++;
	}	
	if(rk%n==0){
		if((rk/n)%2)cout<<rk/n<<' '<<n<<'\n';
		else cout<<rk/n<<' '<<1<<'\n';
		
	}
	else {
		int c = (rk/n)+1 , r = rk%n;
		if(c%2)cout<<c<<' '<<r<<'\n';
		else cout<<c<<' '<<(n+1-r)<<'\n';
		
	}
	return 0;
	
}

