#include<bits/stdc++.h>
using namespace std;
int n,m,a,num=1,temp,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>temp;
		if(temp>a){
			num++;
		}
	}
	if(num%n==0) c=num/n;
	else c=num/n+1;
	cout<<c<<' ';
	if(c%2==1){
		r=num%n;
		if(r==0){
			r=n;
		}
	}
	else{
		r=n-(num%n)+1;
		if(r>n){
			r=1;
		}
	}
	cout<<r;
	return 0;
}
