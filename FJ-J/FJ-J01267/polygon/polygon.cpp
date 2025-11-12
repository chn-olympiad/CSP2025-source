#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],c[5005];
long long ans;
void dfs(long long k,long long s,long long r,long long maxx){
	if(r+n-maxx<k) return;
	if(r==k-1){
		for(int i=maxx+1;i<=n;i++){
			if(s>a[i]) ans=(ans+1)%mod;
			else break;
		}
		return;
	}
	for(int i=maxx+1;i<=n;i++){
		dfs(k,s+a[i],r+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[i-1]+a[i];
	}
	for(int k=3;k<=n;k++){
		dfs(k,0,0,0);
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

