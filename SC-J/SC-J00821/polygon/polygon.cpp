#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005],jc[5005],ans,n,sum[5005],sum1[5005];
int C(int n,int m){
	if(n<0||n>m) return 0;
	n=min(n,m-n);
	int t1=jc[m]/jc[m-n];
	int t2=jc[n];
	return max(t1/t2,0ll);
}
void dfs(int x,int sum,int mx,int cnt){
	if(x>n){
		if(cnt>=3&&sum>2*mx) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,sum,mx,cnt);
	dfs(x+1,sum+a[x],max(mx,a[x]),cnt+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,k,maxx=0,tot=0;
	cin>>n;
	jc[0]=1;
	for(i=1;i<=5000;i++) jc[i]=(jc[i-1]*i)%mod;
	for(i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=3){
		if(n==3){
			if(tot>2*maxx) cout<<"1";
			else cout<<"0";
		}
		else cout<<"0";
		return 0;
	}
	if(maxx==1){
		for(i=3;i<=n;i++) ans=(ans+C(i,n))%mod;
		cout<<ans;
		return 0;
	}
	if(maxx==0){
		cout<<"0";
		return 0;
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(i=n;i>=1;i--) sum1[i]=sum1[i+1]+a[i];
	for(i=3;i<=n;i++){
		int xb=upper_bound(sum+1,sum+i+1,a[i])-sum;
		if(xb>=i) continue;
		int tmp=0;
		for(j=1;j<=xb;j++) if(sum[j]+sum1[i-xb+1]-sum1[xb+1]>a[i]) tmp=(tmp+C(j,xb)*C(xb-j,i-xb)%mod)%mod;
		ans=(ans+tmp)%mod;
//		cout<<tmp<<"\n";
	}
	cout<<ans;
	return 0;
}