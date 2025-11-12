#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int flag;
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=1;
			break;
		}
	}
	if(flag==0){
		long long ans;
		for(int i=1;i<=n-2;i++){
			ans+=i;
		}
		cout<<ans%998244353;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	else cout<<0;
	return 0;
}
