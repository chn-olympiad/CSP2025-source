#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x,ans=1;
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	
	for(int i=n;i>=1;i--){
		ans*=i;
	}
	cout<<ans%998244353;
return 0;
}
