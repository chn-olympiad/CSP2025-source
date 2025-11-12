#include<bits/stdc++.h>
using namespace std;
int n,m,b,c;
int a[109];
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=n*m-i+1;
			break;
		}
	}
	if(c%n==0){
		if(c/n%2==0){
			cout<<c/n<<" "<<1;
		}else{
			cout<<c/n<<" "<<n;
		}
	}else{
		if(c/n%2==0){
			cout<<c/n+1<<" "<<c%n;
		}else{
			cout<<c/n+1<<" "<<n-c%n+1;
		}
	}
	return 0;
}
