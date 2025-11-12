#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long n,m,k,d,r;
long long a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(long long i=n*m;i>=1;i--){
		if(a[i]==k){
			d=n*m-i+1;
		}
	}
	long long q,b;
	q=d/n;
	b=d%n;
	if(b==0){
		if(q%2){
			cout<<q<<" "<<n;
		}else{
			cout<<q<<" "<<"1";
		}	
	}else{
		q=q+1;
		if(q%2){
			cout<<q<<" "<<b;
		}else{
			cout<<q<<" "<<n-b+1;
		}	
	}
return 0;
}
