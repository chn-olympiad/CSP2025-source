#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
inline ll max(ll a,ll b){
	return a>=b ? a:b;
}
inline ll jie(ll a){
	int sum1=1;
	for(int i=1;i<=a;i++){
		sum1=sum1*i%mod;
	}
	return sum1;
}
ll n,a[5050],ans;
bool vis[5050];
ll xuan[5050];
void dfs(ll s,ll len,ll max1,ll la){
	if(s>=3 && len>max1*2){
		ans++;
		ans=ans%mod;
	}
	for(register int i=1;i<=n;i++){
		if(vis[i]==0 && i>=la){
			vis[i]=1;
			xuan[s]=i;
			dfs(s+1,len+a[i],max(max1,a[i]),i);
			xuan[s]=0;
			vis[i]=0;
		}
	}
	
}
bool pian;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	pian=1;
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			pian=0;
		}
	}
	if(pian==1){
		int a1=jie(n);
		for(int i=3;i<=n;i++){
			ans=(ans+(a1/jie(n-i))/jie(i))%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}