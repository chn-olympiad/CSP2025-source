#include <bits/stdc++.h>
using namespace std;
int n,m,s[105],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int xq=s[1];
	sort(s+1,s+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(s[i]==xq){
			ans=n*m-i+1;
			break;
		}
	}
	if(ans/n%2==0){
		if(ans%n==0){
			cout<<ans/n<<" "<<1;
		}else{
			cout<<ans/n+1<<" "<<ans-(ans/n*n);
		}
	}else{
		if(ans%n==0){
			cout<<ans/n<<" "<<n;
		}else{
			cout<<ans/n+1<<" "<<n-(ans-ans/n*n)+1;
		}
	}
	return 0;
}