#include<bits/stdc++.h>
using namespace std;
int b[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,t,c=0,n1,m1;
cin>>n>>m;

for(int i=1;i<=n*m;i++){
	cin>>b[i];
}
t=b[1];
sort(b+1,b+1+n*m);

for(int i=n*m;i>=1;i--){
		c++;
	if(b[i]==t){
	break;
}
}
if(c%n==0){
	m1=c/n;n1=n;
	if(m1%2==1){
		cout<<m1<<" "<<n1;
	}else{
		cout<<m1<<" "<<n-n1+1;
	}
	return 0;
}
if(c%n!=0){
	m1=c/n+1;n1=c-n*(c/n);
	if(m1%2==1){
		cout<<m1<<" "<<n1;
	}else{
		cout<<m1<<" "<<n-n1+1;
	}
	return 0;
}
if(n==1){
	m1=c;n1=1;
	if(m1%2==1){
		cout<<m1<<" "<<n1;
	}else{
		cout<<m1<<" "<<n-n1+1;
	}
	return 0;
}
}
