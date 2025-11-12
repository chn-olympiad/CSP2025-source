#include<bits/stdc++.h>
using namespace std;
int rk=1,lr,n,m,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>lr;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>lr){
			rk++;
		}
	}
	c=(rk-1)/n+1;
	if(c%2==1){
		r=(rk-1)%n+1;
	}else{
		r=n-((rk-1)%n+1)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
