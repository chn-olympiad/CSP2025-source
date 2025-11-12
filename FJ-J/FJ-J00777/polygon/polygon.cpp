#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
int vis[5005];
const long long MOD=998244353;
bool cmp(long long x,long long y){
	return x>y;
}
void f(int m,long long sum,long long maxn,int t){
	if(m>=3 && sum>maxn*2)ans=(ans+1)%MOD;
	for(int i=t;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			f(m+1,sum+a[i],max(a[i],maxn),i+1);
			vis[i]=0;
		}
	}
}
long long c(int n,int m){//nѡm 
	if(n==m)return 1;
	if(m>n/2)return c(n,n-m);
	long long sum=1;
	for(int i=n;i>=n-m+1;i--){
		sum*=i;
		sum%=MOD;
	}
	for(int i=1;i<=m;i++){
		sum/=i;
	}
	return sum%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool st=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)st=0;
	}
	if(st&&n>20){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	f(0,0,0,1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
