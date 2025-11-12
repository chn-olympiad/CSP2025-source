#include<bits/stdc++.h>
using namespace std;
int n,m,k,rate=1,me;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m>>me;//n行m列 
	k=n*m;
	for(int i=2;i<=k;i++){
		int x;cin>>x;
		if(x>me)rate++;
	}
	//rate为第几
	//第c列第r行 
	if(rate%n==0){
		if(rate/n%2==0)cout<<rate/n<<' '<<1;
		else cout<<rate/n<<' '<<n;
	}else{
		int c=((rate-rate%n)/n)+1,r=rate%n;
		if(c%2==1)cout<<c<<' '<<r;
		else cout<<c<<' '<<n-r+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
