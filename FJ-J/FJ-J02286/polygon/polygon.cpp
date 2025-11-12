#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll P=998244353;
ll n,a[5005],ans,len[5005],cnt;
void solve1(){
	ll sum=n*(n-1)*(n-2)/6;
	ans=sum;
	for(ll i=4;i<=n;i++){
		sum=sum*(n+1-i)/i;
		sum%=P;
		ans+=sum;
		ans%=P;
//		cout<<ans<<" ";
	}
	cout<<ans;
}
void solve2(){
	if(n<3) cout<<0;
	else{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
}
void dfs(int now,int k){
	if(k==cnt){
		if(len[k]>2*(len[k]-len[k-1])) ans++;
//		for(int i=1;i<=k;i++) cout<<len[i]-len[i-1]<<" ";
//		cout<<endl;
		return;
	}
	if(now>n) return;
	for(int i=now;i<=n;i++){
		len[k+1]=len[k]+a[i];
		dfs(i+1,k+1);
		len[k+1]=0; 
	}
}
void solve3(){
	for(int i=3;i<=n;i++){
		cnt=i;
		dfs(1,0);
//		cout<<ans<<" ";
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3) solve2();
	else if(a[n]==1) solve1();
	else if(n<=20) solve3();
	else cout<<"fuck";
	return 0;
}
