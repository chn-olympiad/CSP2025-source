#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,ans,mx;
long long a[5004];
void dfs(long long mx,long long tot,long long k,long long cnt){
	long long x=a[k];
	if(k==n){
		if(cnt>=2&&tot>x){
			ans++;
			ans%=998244353;
		}
		if(cnt>=3&&tot>mx*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(x,tot+x,k+1,cnt+1);
	dfs(mx,tot,k+1,cnt);
	return ;
}
long long po(long long x){
	long long t=1;
	for(long long i=1;i<=x;i++){
		t*=i;
		t%=998244353;
	}
	return t;
}
long long C(long long m,long long n){
	return po(m)/(po(n)*po(m-n));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}

