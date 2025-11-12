#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans,n,a[10010];
int b[5050],mx[5050],k,num[5050];
int cnt1;
bool f;
inline void dfs(int x,int f){
	if(f==1){
		b[x]=b[x-1]+a[x];
		mx[x]=max(mx[x-1],a[x]);
	}else{
		b[x]=b[x-1];
		mx[x]=mx[x-1];
	}
	
	if(b[x]>mx[x]*2&&f)ans++;
//	cout<<x<<' '<<b[x]<<' '<<mx[x]<<' '<<ans<<endl;
	if(x==n)return;
	dfs(x+1,1);
	dfs(x+1,0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		else if(a[i]>=2)f=1;
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cout<<1;
		else cout<<0;
	}else if(!f){
		for(int i=1;i<=n-2;i++){
			ans=(ans+((i*i+i)/2)%mod)%mod;
		}
		cout<<ans;
	}else{
		dfs(1,1);
		b[0]=mx[0]=0;
		ans%=mod;
		dfs(1,0);
		cout<<ans%mod;
	}
	return 0;
}
