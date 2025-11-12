#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5001],mx;
long long cnt;
inline void dfs(int id,long long sum,int num,int ma){
	if(id>n){
		if(sum>2ll*ma&&num>=3){
			cnt=(cnt+1ll)%mod;
		}
		return;
	}
	int t=ma;
	ma=max(ma,a[id]);
	dfs(id+1,sum+a[id],num+1,ma);
	dfs(id+1,sum,num,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1){
		long long num1[5001],num2[5001],num3[5001];
		num1[1]=4;
		for(int i=2;i<=n;i++){
			num1[i]=(num1[i-1]*2ll)%mod;
		}
		for(int i=1;i<=n;i++){
			num1[i]-=1ll;
		}
		num2[1]=4;
		for(int i=2;i<=n;i++){
			num2[i]=(num2[i-1]+num1[i])%mod;
		}
		num3[0]=1;
		for(int i=1;i<=n;i++){
			num3[i]=(num3[i-1]+num2[i])%mod;
		}
		cout<<num3[n-3];
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0ll,1,0);
	cout<<cnt%mod; 
	return 0;
} 
// 1 5 16 42 99
