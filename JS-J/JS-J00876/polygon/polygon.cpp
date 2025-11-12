#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const int M=998244353;
ll n,k,s,a[N],ans;
ll ksm(ll a,ll b){
	ll tmp=1;
	while(b){
		if(b&1) tmp=tmp*a%M;
		a=a*a%M;
		b>>=1;
	}
	return tmp;
}
void dfs(ll x,ll sum,ll maxn){
	if(sum>2*maxn){
		//cout<<x<<sum<<maxn<<endl;
		ans=(ans+ksm(2,x-1))%M;
		return;
	}
	if(x==1) return;
	for(int i=x-1;i>=1;i--){
		dfs(i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(n+1,0,0);
	cout<<ans;
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=998244353;
int n,k,s,a[N],ans;
void dfs(int x,int sum){
	if(sum>2*a[x]){
		ans=(ans+1)%M;
	}
	if(x>=n) return;
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	return 0;
}
*/
