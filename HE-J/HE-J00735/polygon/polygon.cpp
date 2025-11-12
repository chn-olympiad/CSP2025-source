#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=5010;
int n,a[N];
int maxn;
ll ans=0;
bool cmp(int xx,int yy){
	return xx<yy;
}
void solve1(){ //all 1
	for(int i=3;i<=n;i++){
		//int dao=n-i;
		ll cnt=1;
		for(int j=n;j>i;j--){
			cnt=(cnt*j)%mod;
		}
		cnt%=mod;
		ans=(ans+cnt)%mod;
	}
	cout<<ans;
	return;
}
void solve2(){ // n = 3
	int sum=a[1]+a[2]+a[3];
	if(sum>2*maxn){
		cout<<1;
	}else{
		cout<<0;
	}
	return;
}
void dfs(int now,int len,int sum,int maxa){
	if(len==0){
		if(sum>2*maxa){
			ans++;
			ans%=mod;
			return;
		}
	}
	if(now==1) return;
	for(int i=now-1;i>=len;i--){
		if(a[i]*(len-1)+sum>maxa){
			dfs(i,len-1,sum+a[i],maxa);
		}
		
	}
	return;
}
int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		solve1();
		return 0;
	}else if(n==3){
		solve2();
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			dfs(j,i-1,a[j],a[j]);
		}
	}
	cout<<ans;
	
	return 0;
}
/*
5
2 2 3 8 10
*/
