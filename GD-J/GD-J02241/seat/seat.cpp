#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105],sum,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	sum++;
	if(sum%n==0){
		cout<<sum/n<<" ";
		if((sum/n)%2==0) cout<<1;
		else cout<<n;
	}
	else{
		cout<<sum/n+1<<" ";
		if((sum/n+1)%2==0) cout<<n-(sum%n)+1;
		else cout<<sum%n;
	}
	return 0;
} 
