#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long r[5005];
void dfs(int l,int x,long long ma,long long z){
	if (l>n)return;
	if (z>2*ma&&l>=3&&l<=n){
		ans++;
		ans=ans%998244353;
	}
	for (int i=x;i<=n;i++){
		dfs(l+1,i+1,max(ma,r[i]),z+r[i]);
	}
	return;
}
long long cw(int x,int y){
	long long a=1,b=1;
	for (int i=x;i>x-y;i--){
		a=a*i%998244353;
	} 
	for (int i=y;i>=1;i--){
		b=b*i%998244353;
	}
	return (a/b)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=0;
	for (int i=1;i<=n;i++){
		cin>>r[i];
		if (r[i]!=1){
			f=1;
		} 
	}
	if (f)dfs(0,1,-1,0);
	else{
		for (int i=3;i<=n;i++){
			ans=ans+cw(n,i);
		}
	}
	cout<<ans;
	return 0;
}
