#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],maxx,f[5005],ans,m;
bool e(int x,int y) {
	return x<y;
}
void dfs(int w,bool b,int h) {
	if(h==0&&n-w+1<3) return ;
	if(b) h+=a[w];
	if(w<n) w++;
	else return ;
	if(h>a[w]) ans=(ans+1)%mod;
	dfs(w,0,h);
	dfs(w,1,h);
}
long long w(long long x,long long y) {
	long long sum=1;
	for(long long i=1;i<=y;i++) sum=sum*x%mod;
	return sum%mod;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,e);
	if(a[n]<=1) {
		cout<<(w(2,n)-1-n-n*(n-1)/2)%mod;
		return 0;
	}
	dfs(1,1,0);
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
/*5
2 2 3 8 1*/
