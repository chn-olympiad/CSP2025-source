#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int ans=0,n;
int a[N];
void dfs(int s,int sum,int step,int mx){
	if(sum>2*mx && step>=3){
		ans++;
	}else if((step<3 && sum>2*mx) || (step>n)){
		return ;
	} 
	for(int i=s+1;i<=n;i++){
		dfs(i,sum+a[i],step+1,max(mx,a[i]));
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<"1";
		else cout<<"0";
	}else if(n<=10){
		for(int i=1;i<=n;i++){
			dfs(i,a[i],1,a[i]);
		}
		cout<<ans%998244353;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(i,a[i],1,a[i]);
		}
		cout<<ans%998244353;
	}else if(n<=500){
		for(int i=1;i<=n;i++){
			dfs(i,a[i],1,a[i]);
		}
		cout<<ans%998244353;
	}
	return 0;
}
