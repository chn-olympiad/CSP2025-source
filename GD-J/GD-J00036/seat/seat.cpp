#include <bits/stdc++.h> 
using namespace std;
int n,m,a[1005];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			id=n*m-i+1;
		}
	}
	if((id/n)%2==1&&id%n==0||(id/n)%2==0&&id%n!=0){
		
		if(id%n==0){
			cout<<id/n<<" "<<n;
		}else{
			cout<<id/n+1<<" "<<id%n;
		}
	}else{
		if(id%n==0){
			cout<<id/n<<" "<<1;
		}else{
			cout<<id/n+1<<" "<<n-id%n+1;
		}
	}
	return 0;	
}
