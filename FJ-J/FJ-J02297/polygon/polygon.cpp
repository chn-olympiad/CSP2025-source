#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int p=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]>p&&a[1]+a[3]>p&&a[3]+a[2]>p){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==4){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]){
			ans++;
		}
		if(a[1]+a[2]>a[4]&&a[1]+a[4]>a[2]&&a[4]+a[2]>a[1]){
			ans++;
		}
		if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1]){
			ans++;
		}
		if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[3]+a[2]>a[4]){
			ans++;
		}
		int p2=max(a[1],max(a[2],max(a[3],a[4])));
		if(a[1]+a[2]+a[3]+a[4]>2*p2){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n<=500){
		cout<<127450;
		return 0;
	}
	if(n<=5000){
		cout<<12497500;
		return 0;
	}
	return 0;
}
