#include<bits/stdc++.h>
using namespace std;
long long n,m,c[10000],sum=1;
int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	for(int i=2;i<=n*m;i++){
		if(c[1]<c[i]) sum++;
	}
	if(sum%n==0){
		if(sum%2==1) cout<<sum/n<<" "<<n;
		else cout<<sum/n<<" "<<1;
	}
	else{
		if(sum%2==1)  cout<<sum/n+1<<" "<<sum%n;
		else cout<<sum/n+1<<" "<<n-sum%n+1;
	}
	return 0;
}
