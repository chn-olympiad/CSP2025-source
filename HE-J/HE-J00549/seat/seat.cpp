#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s,n,m,c,r;
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+d+1);
	for(int i=d;i>=1;i--){
		if(a[i]==s){
			s=d-i+1;
			break;
		}
	}
	c=s/n;
	r=s%n;
	if(r!=0){
		c++;
		if(c%2==0){
			r=n-r+1;
		}
	}else{
		if(c%2==0){
			r=1;
		}else{
			r=n;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
