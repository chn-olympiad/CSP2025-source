#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			ans++;
		}
	}
	cout<<(ans+n-1)/n<<" ";
	if((ans+n-1)/n%2==1){
		if(ans%n==0){
			cout<<n<<endl;
		}else{
			cout<<ans%n<<endl;
		}
	}else{
		if(ans%n==0){
			cout<<1<<endl;
		}else{
			cout<<n-ans%n+1<<endl;
		}
	}
	return 0;
} 