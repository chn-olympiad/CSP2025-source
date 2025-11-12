#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,tmp;
	cin>>n>>m>>x;
	int ans0 = 0;
	for(int i = 1;i < n*m;i++){
		cin>>tmp;
		if(tmp>x) ans0++;
	}
	//cout<<ans0;
	cout<<1+ans0/n<<' ';
	if((1+ans0/n)%2==0){
		cout<<n-ans0%n;
	}
	else{
		cout<<1+ans0%n;
	}
	return 0;
} 
