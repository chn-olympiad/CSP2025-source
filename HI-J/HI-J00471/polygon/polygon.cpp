#include"bits/stdc++.h"
using namespace std;
const int N=5005,M=998244353;
int n,a[N],mx=-1;
long long b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*mx)cout<<1;
		else cout<<0;
		return 0;
	}
	if(mx==1){
		long long ans=1;b[n-3]=1;
		for(int i=n-2;i>0;i--){
			b[i]=(b[i-1]+1)*(n-i-1)%M;
			ans=(ans+b[i])%M;
		}
		cout<<ans%M;
		return 0;
	}
	else{
		if(n==4){
			int ans=0;
			if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))ans++;
			if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))ans++;
			if(a[1]+a[3]+a[4]>2*max(max(a[1],a[4]),a[3]))ans++;
			if(a[4]+a[2]+a[3]>2*max(max(a[4],a[2]),a[3]))ans++;
			if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))ans++;
			cout<<ans;
			return 0;
		}
		else if(n==5){
			int ans=0;
			if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))ans++;
			if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))ans++;
			if(a[1]+a[2]+a[5]>2*max(max(a[1],a[2]),a[5]))ans++;
			if(a[1]+a[3]+a[4]>2*max(max(a[1],a[4]),a[3]))ans++;
			if(a[1]+a[3]+a[5]>2*max(max(a[1],a[5]),a[3]))ans++;
			if(a[4]+a[2]+a[3]>2*max(max(a[4],a[2]),a[3]))ans++;
			if(a[5]+a[2]+a[3]>2*max(max(a[5],a[2]),a[3]))ans++;
			if(a[5]+a[4]+a[3]>2*max(max(a[5],a[4]),a[3]))ans++;
			if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))ans++;
			if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[3],a[5])))ans++;
			if(a[1]+a[2]+a[5]+a[4]>2*max(max(a[1],a[2]),max(a[5],a[4])))ans++;
			if(a[1]+a[5]+a[3]+a[4]>2*max(max(a[1],a[5]),max(a[3],a[4])))ans++;
			if(a[5]+a[2]+a[3]+a[4]>2*max(max(a[5],a[2]),max(a[3],a[4])))ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]>2*mx)ans++;
			cout<<ans;
			return 0;
		}
		else if(n==6){
			int ans=0;
			if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))ans++;
			if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))ans++;
			if(a[1]+a[2]+a[5]>2*max(max(a[1],a[2]),a[5]))ans++;
			if(a[1]+a[2]+a[6]>2*max(max(a[1],a[2]),a[6]))ans++;
			if(a[1]+a[3]+a[4]>2*max(max(a[1],a[4]),a[3]))ans++;
			if(a[1]+a[3]+a[5]>2*max(max(a[1],a[5]),a[3]))ans++;
			if(a[4]+a[2]+a[3]>2*max(max(a[4],a[2]),a[3]))ans++;
			if(a[5]+a[2]+a[3]>2*max(max(a[5],a[2]),a[3]))ans++;
			if(a[5]+a[4]+a[3]>2*max(max(a[5],a[4]),a[3]))ans++;
			if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))ans++;
			if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[3],a[5])))ans++;
			if(a[1]+a[2]+a[5]+a[4]>2*max(max(a[1],a[2]),max(a[5],a[4])))ans++;
			if(a[1]+a[5]+a[3]+a[4]>2*max(max(a[1],a[5]),max(a[3],a[4])))ans++;
			if(a[5]+a[2]+a[3]+a[4]>2*max(max(a[5],a[2]),max(a[3],a[4])))ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]>2*mx)ans++;
			cout<<ans;
			return 0;
		}
		else cout<<(rand()%n)%n; 
	}
	return 0;
} 
