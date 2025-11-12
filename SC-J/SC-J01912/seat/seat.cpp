#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long r=a[1];
	long long c;
	sort(a+1,a+1+n*m);
	for(int i=m*n;i>=1;i--){
//		cout<<a[i];
		if(a[i]==r){
			c=m*n-i+1;
//			cout<<c<<" ";
			break;
		}
	}
	long long b;
	if(c%n>0){
		cout<<c/n+1<<" ";//<<c%n
		b=c/n+1;
	}else{
		cout<<c/n<<" ";//<<c%n
		b=c/n;
	}
	if(b%2==1){
		long long l;
		if(c%n==0){
			l=n;
		}else{
			l=c%n;
		}
		cout<<l;
	}else{
		cout<<n-c%n+1;
	}
	return 0;
}