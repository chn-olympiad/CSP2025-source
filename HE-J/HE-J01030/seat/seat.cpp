#include<bits/stdc++.h>
using namespace std;
int n,m,shu,xb,x,y,sum;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	shu=a[1];
	sort(a+1,a+1+sum,greater<int>());
	for(int i=1;i<=sum;i++){
		if(shu==a[i]){
			xb=i;
			break;
		}
	}
	if(xb%n!=0){
		y=xb/n+1;
		if(y%2==0){
			x=n-(xb%n)+1;
		}
		else{
			x=xb%n;
		}
	}
	else{
		y=xb/n;
		if(y%2==0){
			x=1;
		}
		else{
			x=n;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
