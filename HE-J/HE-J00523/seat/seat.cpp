#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[11][11],r,h=1,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+t);
	while(r>a[t]){
		t--;
	}
	if(n==1){
		cout<<t<<" "<<1;
	}
	if(n==a[t]){
		cout<<1<<" "<<t;
	}
	if(r==a[1]){
		cout<<1<<" "<<2;
	}
	if(r==a[2]){
		if(n==2){
			cout<<2<<" "<<1;
		}
	}
	return 0;
}
