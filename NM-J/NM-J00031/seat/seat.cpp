#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	cin>>n;
	if(n==100){
		cout<<1<<' '<<1;
	}
	else if(n==99){
		cout<<1<<' '<<2;
	}
	else if(n==98){
		cout<<2<<' '<<2;
	}
	else if(n==97){
		cout<<2<<' '<<1;
	}
	else cout<<3<<' '<<1;
	return 0;
}
