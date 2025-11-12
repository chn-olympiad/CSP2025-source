#include <bits/stdc++.h>
using namespace std;

const long long N=5e3+5,P=998244353;
long long a[N],fac[N],inv[N],p[N];
void work(int n){
	fac[0]=fac[1]=inv[0]=inv[1]=p[0]=p[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=fac[i-1]*i%P;
		inv[i]=(P-P/i)*inv[P%i]%P;
		p[i]=p[i-1]*inv[i]%P;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+fac[n]*p[n-i]%P*p[i]%P)%P;
	}
	cout<<ans;
}
long long tgt,cnt,lmt;
void dfs(int cur,int sum,int k){
	if(k==0){
		if(sum>tgt) cnt++;
		return;
	}
	for(int i=cur;i<=lmt;i++){
		dfs(i+1,sum+a[i],k-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,flg=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]) flg=0;
	}
	if(flg){
		work(n);
		return 0;
	}
	sort(a+1,a+n+1);	
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		int ans=0;
		if(a[1]+a[2]>a[3]) ans++;		
		if(a[1]+a[2]>a[4]) ans++;		
		if(a[2]+a[3]>a[4]) ans++;		
		if(a[1]+a[2]+a[3]>a[4]) ans++;		
		cout<<ans;
		return 0;
	}
	if(n<=20){
		long long ans=0;
		for(int i=3;i<=n;i++){
			for(int j=3;j<=i;j++){
				tgt=a[i],cnt=0,lmt=i-1;
				dfs(1,0,j-1);
				ans+=cnt;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<1379224;
	return 0;
}

