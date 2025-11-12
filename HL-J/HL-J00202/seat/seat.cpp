#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,a[105],x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	}
	if(x%n==0){
		cout<<x/n<<" "<<n;
	}
	else if(x/n%2==0){
		cout<<x/n+1<<" "<<x%n;
	}
	else{
		cout<<x/n+1<<" "<<n-x%n+1;
	}
	return 0;
}
