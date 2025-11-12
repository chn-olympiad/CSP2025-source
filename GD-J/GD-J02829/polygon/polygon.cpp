#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,k,j,l,r,a[1000000+10],b[1000000+10],x,o,z,ln,rl,ans;
int A(int n,int m){
	int fl=1;
	for(int i=1;i<=m;i++){
		fl*=n;
		n--;
		fl%=mod;
	} 
	return fl%mod;
}
int C(int n,int m){
	return A(n,m)/A(m,m);
}
void dfs(int bi,int fl,int k){
	if(bi==1){
		for(int i=k;i<=n;i++){
			if(fl>i) ans++;
			else{                           
				break;
			} 
		}
		ans%=mod;
		return ;
	}
	for(int i=k;i<=n;i++){
		dfs(bi-1,fl+a[i],i+1);
	}
}
void work(int bi){
	dfs(bi,0,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o+=(a[i]==1);
	}
	if(o==n){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3] or a[1]+a[2]>a[2] or a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		work(i);
	}
	cout<<ans;
	return 0;
} 
