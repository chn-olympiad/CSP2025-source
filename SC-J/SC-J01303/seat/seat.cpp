#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,R,p,a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			p=n*m-i+1;
			break;
		}
	}
	if(p%n==0){
		cout<<p/n<<" ";
		if((p/n)%2!=0){
			cout<<n;
		}
		else if((p/n)%2==0){
			cout<<1;
		}
	}
	else if(p%n!=0){
		cout<<p/n+1<<" ";
		if((p/n)%2!=0){
			cout<<n+1-p%n;
		}
		else if((p/n)%2==0){
			cout<<p%n;
		}
	}
	return 0;
}