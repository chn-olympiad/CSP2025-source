#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c,d;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==b){
			c=n*m-i+1;
			break;
		}
	}
	if(c%n!=0){
		d=c/n; 
		cout<<d+1<<" ";
		if(d%2!=0){
			cout<<n-c%n+1;
		}else{
			cout<<c%n;
		}
	}else{
		cout<<c/n<<" ";
		if((c/n)%2==0)cout<<"1";
		else cout<<n;
	}
	return 0;
} 
