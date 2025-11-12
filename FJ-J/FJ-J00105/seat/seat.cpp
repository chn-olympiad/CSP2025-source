#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],sum;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2&&a[i]>a[1]){
			sum++;
		}
	}
	sum++;
	if(sum%n==0){
		if(sum/n%2==0) cout<<sum/n<<' '<<1;
		else cout<<sum/n<<' '<<n;
	}else{
		if(sum/n%2==0) cout<<sum/n+1<<' '<<sum%n;
		else cout<<sum/n+1<<' '<<n+1-sum%n;
	}
	return 0;
}
