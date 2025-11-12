#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],i,j,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}t=a[1];
	sort(a,a+n+1);
	for(i=n*m;i>=1;i--){
		if(a[i]==t)
			break;
		
	}if((n*m-i+1+n)%n!=0)
	cout<<(n*m-i+1)/n+1<<" "<<(n*m-i+1+n)%n;
	else
	cout<<(n*m-i+1)/n<<" "<<n;
	return 0;
}
