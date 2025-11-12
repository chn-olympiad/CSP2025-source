#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010];
int st[5010];
int mod=998244353;
int n;
int ans=0;int an=0;
void dfs(int k,int c,int sum,int mx){
	if(c==k+1){
		if(sum>mx*2){
			an++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==1)continue;
		st[i]=1;
		dfs(k,c+1,sum+a[i],max(mx,a[i]));
		st[i]=0;
	}
	return;
}
int jie(int a){
	int sum=1;
	for(int i=2;i<=a;i++){
		sum*=i;
	}
	return sum;
}
void so(){
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=2;
		sum%=mod;
	}
	sum=(sum-1)%mod;
	cout<<(sum-n-(n*(n-1)/2))%mod;
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f==1){
		so();
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	sort(a+1,a+n+1);	
	for(int i=3;i<=n;i++){
		dfs(i,1,0,0);
		ans+=(an/jie(i))%mod;
		an=0;
	}
	cout<<ans<<endl;
	return 0;
}
