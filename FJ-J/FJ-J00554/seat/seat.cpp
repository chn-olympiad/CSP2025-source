#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o=1,on,om,b,c;
	cin>>n>>m;
	int a[n*m];
	const int l=n*m;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	for(int i=1;i<l;i++){
		if(a[i]>a[0]){
			o++;
		}
	}
	if(o<=n){
		cout<<1<<' '<<o;
		return 0;
	}
	b=o%n;
	c=o/n;
	om=c;
	if(b){
		om++;
	}
	if(c%2==1){
		on=n;
		on-=b-1;
	}
	else{
		on=1;
		on+=b-1;
	}
	cout<<om<<' '<<on;
	return 0;
}
