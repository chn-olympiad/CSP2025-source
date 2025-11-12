#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e3+10;
const ll mod=998244353;
int Max=0,n,a[N],qzh[N];
ll ans;
int v[N];
void pt(int cnt){
	for(int i=1;i<=cnt;i++) cout<<v[i]<<' ';
	cout<<endl;
}
bool check(int cnt){
	
	int M=0,sum=0;
	for(int i=1;i<=cnt;i++){
		sum+=v[i],M=max(M,v[i]);
	}
//	pt(cnt);
	return sum>M*2;
}
ll pow(int a,int b){
	if(b==1) return a;
	ll ret=1;
	ret=pow(a,b/2);
	if(b%2) return ret*ret*a%mod;
	else return ret*ret%mod;
}
void dfs(int i,int cnt){//O(n*2^n)
	if(i==n){
		if(cnt<=2) return;
		if(check(cnt)) ans++;
		ans%=mod;
		return;
	}
//	printf("i=%d cnt=%d\n",i,cnt);
	v[cnt+1]=a[i+1];
	dfs(i+1,cnt+1);
	dfs(i+1,cnt);
	
	
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
		Max=max(Max,a[i]);
	}
	if(Max*2>=qzh[n]){
		cout<<0;
		return 0;
	}
	if(Max==1){//2^n-C(1,n)-C(2,n)-1
		ll ans=pow(2,n)-n-(n*(n-1))/2-1;
		cout<<ans;
		return 0;
	}else{
		dfs(0,0);
		cout<<ans;
		return 0;	
	}
	return 0;
} 
