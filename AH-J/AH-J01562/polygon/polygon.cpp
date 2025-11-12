#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans;
int a[5005],b[5005],vis[5005],n;
void dfs(int l,int s,int x,int mx){
	if(s==l+1){
		if(x>2*mx){
//			cout<<l<<":";
//			for(int i=1;i<=l;i++) cout<<b[i]<<" ";
//			cout<<"\n";
			ans=(ans+1)%MOD;
		}
		return;
	}
	for(int i=b[s-1]+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[s]=i;
			dfs(l,s+1,x+a[i],max(mx,a[i]));
			vis[i]=0;
			b[s]=0;
		}                   
	}
}
long long C(int n,int m){
	m=min(m,n-m);
	long long x=1;
	for(int i=n;i>=n-m+1;i--){
		x=x*i%MOD;
	}
	for(int i=2;i<=m;i++){
		x/=i;
	}
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ff=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) ff=0;
	}
	if(!ff){
		for(int i=3;i<=n;i++){
			dfs(i,1,0,0);
		}
		cout<<ans%MOD;
	}
	else{
		if(n%2==0){			
			for(int i=1;i<=n/2;i++){
				ans=(ans+C(n,i))%MOD;
			}
		}
		else{
			for(int i=1;i<=n/2;i++){
				ans=(ans+C(n,i))%MOD;
			}
			ans=(ans+C(n,n/2+1))%MOD;
		}
		cout<<ans;
	}
	return 0;
}
