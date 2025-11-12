#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int s=a[0];
	sort(a,a+n*m);
	int f[101];
	for(int i=n*m-1;i>=0;i--){
		f[n*m-i-1]=a[i];
	}
	int ans;
	for(int i=0;i<n*m;i++){
		if(f[i]==s){
			ans=i;
			break;
		}
	}
	ans++;
	if(ans/n*n != ans){
		cout<<ans/n+1<<' ';
		if((ans/n+1)%2==1){
			cout<<ans%n;
		}else{
			cout<<n-ans%n+1;
		}
	}
	else{
		cout<<ans/n<<' ';
		if((ans/n+1)%2==1){
			cout<<1;
		}else{
			cout<<n;
		}
	}
	return 0;
} 
