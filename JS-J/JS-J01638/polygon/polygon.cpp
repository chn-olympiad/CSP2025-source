#include<bits/stdc++.h>
using namespace std;
int n,mod=998244353,ans;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t=1<<n;
	for(int i=1;i<=t;i++){
		long long sum=0,maxx=0;
		for(int j=n,x=i;j>0 && x;j--,x>>=1){
			if(x&1) sum+=a[j],maxx=max(maxx,a[j]);
		}
		if(sum>maxx*2) ans=(ans+1)%mod;
	}
	cout<<ans;
	return 0;
}
