#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	for(int i=1;i<=n*m;i++){
		if(sum==a[i]) sum=n*m-i+1;
	}
	cout<<sum<<" ";
	if(sum%n==0){
		if(sum/n%2==0) cout<<sum/n<<" "<<1;
		else cout<<sum/n<<" "<<n;
	}
	else{
		if((sum/n+1)%2==0) cout<<(sum/n)+1<<" "<<n-(sum%n)+1;
		else cout<<(sum/n)+1<<" "<<sum%n;
	}
	return 0;
} 
