#include<bits/stdc++.h>
using namespace std;
int n,a[100001],ans,t[100001],ma,q[100001];
void dfs(int x,int sum,int u,int m,int c) {
	if(c!=1) {
		ans+=t[min(ma,sum-1)]-t[m-1]-u;
		ans=ans%998244353;
	}
	int o=x+1;
	for(int i=x+1; i<=n; i++) {
		if(a[i]!=a[i-1]){
			o=i;
		}
		if(a[i]==a[i-1]&&i!=o+1){
			continue; 
		}
		if(a[i]!=a[x]) {
			dfs(i,sum+a[i],1,a[i],c+1);
		}else{
			dfs(i,sum+a[i],u+1,a[i],c+1);
		}
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		t[a[i]]++;
		ma=max(ma,a[i]);
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>ma*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1; i<=ma; i++) {
		t[i]+=t[i-1];
	}
	sort(a+1,a+n+1);
	/*for(int i=1; i<=n; i++) {
		q[i]=a[i]+q[i-1];
	}
	for(int i=1; i<=n; i++) {
		bool b=true;
		int u=1;
		if(a[i-1]!=a[i]) {
			b=false;
		}
		for(int j=i+1; j<=n; j++) {
			if(a[j]==a[j-1]) {
				u++;
			} else {
				u=1;
			}
			if(b&&a[j]==a[i]) {
				continue;
			}
			b=false;
			ans+=t[min(ma,q[j]-q[i-1]-1)]-t[j-1]-u;
		}
	}*/
	for(int i=1;i<=n;i++){ 
		dfs(i,a[i],1,a[i],1);
	}
	
	cout<<ans;

	return 0;
}
