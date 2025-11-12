#include<bits\stdc++.h>
using namespace std;
long long n,m,s[6000],a[6000],ans,vis[6000];
void f(long long k,long long sum,long long maxx){
	if(k==n+1){
		if(sum>maxx*2) ans++;
		ans%=998244353;
		return;
	}
	f(k+1,sum+a[k],max(maxx,a[k]));
	f(k+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f(1,0,0);
	cout<<ans;
	return 0;
}
