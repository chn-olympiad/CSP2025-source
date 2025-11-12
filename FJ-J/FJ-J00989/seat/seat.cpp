#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n*m+1],b,sum=0;
	cin>>a[1];
	b=a[1];
	for(long long i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>b) sum++;
	}
	if(a[1]==1) cout<<"1 1";
	else if(sum%n==0){
		long long c=sum/n+1;
		cout<<c<<" ";
		if(c%2==0) cout<<n<<" ";
		else cout<<"1"<<" ";
	}else{
		long long c=(sum+1)/n;
		cout<<c<<" ";
		if(c%2==0) cout<<n-sum%n+1<<" ";
		else cout<<sum%n+1<<" ";
	}
	
	return 0;
}
