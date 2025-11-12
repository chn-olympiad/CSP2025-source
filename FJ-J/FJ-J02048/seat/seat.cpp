#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>x){
			s++;
		}
	}
	if(s%(n*2)>n){
		cout<<(s+n-1)/n<<" "<<n-s%n+1;
	}else{
		cout<<(s+n-1)/n<<" "<<(s-1)%n+1;
	}
	return 0;
}
