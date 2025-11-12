#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,cnt;
const ll N=998244353;
ll a[5010],f[5010],pre[5010];
vector<ll>ve;
ll pow1(ll a,ll b){
	ll sum=1;
	for(ll i=1;i<=b;i++){
		sum*=a;
		sum%=N;
	}
	return sum;
}
void dfs(ll step,ll ans){
	if(step>n){
		if(ans<3)return;
		ll sum=0,maxn=0;
		for(auto c:ve){
			sum+=c;
			maxn=max(maxn,c);
		}
		if(sum<=maxn*2)return;
		cnt++;
//		for(auto c:ve){
//			cout<<c<<' ';
//		}
//		cout<<'\n';
		return;
	}
	dfs(step+1,ans);
	ve.push_back(a[step]);
	dfs(step+1,ans+1);
	ve.pop_back();
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	sort(a+1,a+n+1); 
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' '; 
//	}
//	cout<<'\n';
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0);
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	f[1]=f[2]=0;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1];
		if(pre[i-1]<a[i]*2)continue;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
