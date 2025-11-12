#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],x,cnt,d,ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i;j++){
			if(a[j]<a[i])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(d==a[i]){
			ans=i;
			//cout<<i<<" ";
			break;
			//cout<<i<<" ";
		}
		
	}
	if(ans<=n){
		cout<<1<<" "<<ans;
		return 0;
	}
	if((ans/n+1)%2==0){
		cout<<ans/n+1<<" "<<n-ans%n+1;
		return 0;
	}else{
		if(ans%n==0){
			cout<<ans/n<<" "<<1;
			return 0;
		}
		cout<<ans/n+1<<" "<<ans%n;
	}
	
		return 0;
}



