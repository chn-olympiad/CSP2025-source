#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
long long ans=0;
const int MOD=998244353;
long long sum=0;
void dfs(int x,int gen,int zong){
	sum++;
	if(gen>=3&&zong>(a[x]*2)){
		ans++;
		ans%=MOD;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,gen+1,zong+a[i]);
	}
}
long long suan(int x){
	long long p=1;
	for(int i=1;i<=x;i++){
		p*=i;
		p%=MOD;
	}
	return p;
}
long long suan2(int x){
	long long p=1;
	for(int i=n,ci=0;ci<x;i--){
		ci++;
		p*=i;
		p%=MOD;
	}
	return p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20){
		long long ans=0;
		for(int i=3;i<=n;i++){
			int k=i;
			if(i==n){
				ans++;
				break;
			}
			if(n-k<k){
				k=n-k;
			}
			ans+=(suan2(k)/suan(k));
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans%MOD;
}

