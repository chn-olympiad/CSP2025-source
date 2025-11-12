#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int r;
int id;
int cmp(int x,int y){
	return x>y;
}
int b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			id=i;
			break;
		}
	}
	if(id%n==0){
		b=id/n;
	}else{
		b=id/n+1; 
	}
	if(b%2==1){
		if(id%n!=0){
			c=id%n;
		}else{
			c=n;
		}
	}else{
		if(id%n!=0){
			c=id%n;
		}else{
			c=n;
		}
		c=n+1-c;
	}
	cout<<b<<" "<<c;
	return 0;
}