#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,P=998244353;
int n,a[N],ans;
void dfs(int x,int s,int mx){
	if(x>n){
		if(s>2*mx)ans++;
		return;
	}
	dfs(x+1,s+a[x],max(mx,a[x]));
	dfs(x+1,s,mx);
}
int qpow(int x,int n){
	if(n==0)return 1;
	int t=qpow(x,n/2);
	if(n%2==1)return t*t%P*x%P;
	return t*t%P;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20){
		cout<<((qpow(2,n)-1-n-n*(n-1)/2)%P+P)%P;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans%P;
}
