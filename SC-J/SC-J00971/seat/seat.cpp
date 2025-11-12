#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[1010],ans,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	for(int i=100;i>=a[1];i--){
		ans+=b[i];
	}
	c=ans/n+(ans%n!=0);
	if(c%2==0){
		r=n-ans%n+1;
	}else{
		r=(ans%n==0)?n:ans%n;
	}
	cout<<c<<' '<<r;
	return 0;
} 