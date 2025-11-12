#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long f(int a,int b){
	if(a==b){
		return 1;
	}
	if(b==1){
		return a; 
	}
	b=min(b,a-b);
	long long ans=1;
	int ind=1;
	for(int i=a;i>=0;i--){
		ans*=i;
		ind++;
		if(ind>b){
			break;
		}
	}
	for(int i=b;i>=2;i--){
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1 or n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3]))){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(a[i],mx);
	}
	if(mx==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=f(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
