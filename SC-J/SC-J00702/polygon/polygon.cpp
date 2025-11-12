#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar();
	}
	x*=f;
}
const int N = 100010;
const int mod = 998244353;
int n,a[N],u[N],ans;
void dfs(int dep,int val,int sum,int mx){
	if(dep==n+1){
		if(sum<3) return;
		if(val<=mx*2) return;
		ans++;
		ans%=mod;
		return;
	}
	u[dep]=1;
	dfs(dep+1,val+a[dep],sum+1,a[dep]);
	u[dep]=0;
	dfs(dep+1,val,sum,mx);
	return; 
}
int get(int n,int m){
	int sum=1,num=1;
	int x=n,y=1;
	for(int i=1;i<=m;i++){
		sum*=x,x-=1;
		sum%=mod;
	} 
	for(int i=1;i<=m;i++) num*=y,y++,num%=mod;
	return sum/num%mod;	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n>=500){
		int sum=0;
		for(int j=3;j<=n;j++){
			sum+=get(n,j);
			sum%=mod;
		}
		cout<<sum%mod;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}