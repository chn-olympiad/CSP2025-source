#include<bits/stdc++.h>
using namespace std;
int a[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			c=n*m-i+1;
			break;
		}
	}if(c%n==0){
		cout<<c/n<<' ';
		if(c/n%2==0){
			cout<<1;
			return 0;
		} 
		if(c/n%2!=0){
			cout<<n;
			return 0;
		} 
	}if(c%n!=0){
		cout<<c/n+1<<' ';
		if((c/n+1)%2==0){
			cout<<n-c%n+1;
			return 0;
		} 
		if((c/n+1)%2!=0){
			cout<<c%n;
			return 0;
		} 
	}
	return 0;
} 
