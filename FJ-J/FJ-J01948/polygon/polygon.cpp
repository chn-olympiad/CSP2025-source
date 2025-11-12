#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=998244353;

int n,a[N],e[N],m;
long long ans;
void dfs(int t,int sum,int s,int k){
	if(t==k){
		if(sum>m) sum=m+1;
		ans+=e[sum]-s;
		ans%=mod;
	}else{
		for(int i=s+1;i<n;i++){
			dfs(t+1,sum+a[i],i,k);
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
	sort(a+1,a+n+1);
	if(a[1]==1 && a[n]==1){
		for(int i=3;i<=n;i++){
			long long sum=1,k=2,l=min(i,n-i),x=l;
			for(int j=n;j>=max(i,n-i)+1;j--){
				sum*=j;
				if(l>=k) l--,x*=l;
				long long h=__gcd(x,sum);
				sum/=h,x/=h;
			}
			ans=(ans+sum%mod)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=e[i-1];;j++){
			if(a[j]>=i){
				e[i]=j-1;
				break;
			}
		}
	}
	e[m+1]=n;
	for(int i=2;i<n;i++){
		dfs(0,0,0,i);
	}
	cout<<ans;
	return 0;
}
