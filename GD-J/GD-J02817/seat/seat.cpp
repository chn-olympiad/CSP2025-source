#include <bits/stdc++.h>
using namespace std;
int n,i,m,j,k,p,t,x,y;
int a[103];
bool cmp(int a,int b){
	return a>b;
}
int sol(int x,int b){
	return (x+b-1)/b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(i=1;i<=p;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+p+1,cmp);
	for(i=1;i<=p;i++){
		if(a[i]==k){
			t=i;
			break;
		}
	}
	y=sol(t,n);
	if(y%2==0){
		x=(n+1)-((t-1)%n+1);
		//cout<<t<<' ';
	}
	else{
		x=(t-1)%n+1;
	}
	cout<<y<<' '<<x;
	return 0;
}

