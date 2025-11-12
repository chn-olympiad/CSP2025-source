#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5100;
const int mod=998244353;
int n;
int a[N];
int t[N];
int ans;
int qpow(int x,int y){
	if(y==1)return x;
	if(y%2==0)return qpow(x,y/2)%mod*qpow(x,y/2)%mod;
	else return qpow(x,y/2)%mod*qpow(x,y/2)%mod*x%mod;
}
int jc[N],imjc[N];
int C(int i,int j){
	return jc[i]*imjc[j]%mod*imjc[i-j]%mod;
}
int c[N];
void init(){
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	imjc[n]=qpow(jc[n],mod-2)%mod;
	for(int i=n-1;i>=0;i--){
		imjc[i]=imjc[i+1]*(i+1)%mod;
	}
	for(int i=1;i<=510;i++){
		for(int j=i;j>=1;j--){
			c[i]+=C(i,j);
			c[i]%=mod;
		}
	}
}
void dfs(int rest,int last){
	if(rest<=0){
		ans++;
		ans+=c[last-1];
		ans%=mod;
		return;
	}
	for(int i=last-1;i>=1;i--){
		dfs(rest-a[i],i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	for(int i=3;i<=n;i++){
//		cout<<i<<endl;
		dfs(a[i]+1,i);
	}
	cout<<ans;
}
