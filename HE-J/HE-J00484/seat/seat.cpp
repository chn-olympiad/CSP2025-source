#include<bits/stdc++.h>
using namespace std;
int n,m;
int now,a,ma=1,ansn,ansm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>now;
	for(int i=2;i<=n*m;i++){
		read(a);
		if(a>now){
			ma++;
		}
	}
	ansm=(ma+n-1)/n;
	ma%=n;
	if(ansm%2==0){
		if(ma==0){
			cout<<ansm<<" "<<1;
		}else cout<<ansm<<" "<<n-ma+1;
	}else{
	if(ma==0){
		cout<<ansm<<" "<<n;
	}else{
		cout<<ansm<<" "<<ma;
	}
	}
	return 0;
}
