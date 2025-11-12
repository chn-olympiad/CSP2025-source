#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,r,op;
	long long xh=1;
	cin>>n>>m;
	int aa[15][15];
	cin>>r;
	for(int i=1;i<n*m;i++){
		cin>>op;
		if(r<op){
			xh++;
		}
	}
	int hu;
	if(xh%n>0){
		hu=xh/n+1;
		cout<<hu;
	}else{
		hu=xh/n;
		cout<<hu;
	}
	cout<<' ';
	if(hu%2==1){
		if(xh%n==0){
			cout<<xh;
		}else{
			cout<<xh%n;
		}
		
	}else{
		cout<<n-xh%n+1;
	}
	return 0;
} 
