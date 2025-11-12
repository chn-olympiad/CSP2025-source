#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5004],s[5005],ans;
long long po(long long x,long long y){
	long long k=1;
	while(y){
		if(y%2==1)k=k*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return k;
}
bool vis[105];
int d[5005],summ=0;
void dfs(int x,int y){
	if(x>n)return ;
	if(x>=3&&summ>d[x]*2){
		ans++;
	}
	for(int i=y+1;i<=n;i++){
		d[x+1]=a[i];
		summ+=a[i];
		dfs(x+1,i);
		summ-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	} 
	if(n>20){
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(long long j=n;j>=n-i+1;j--){
				sum*=j;
				sum%=mod;
			}
			for(long long j=1;j<=i;j++){
				sum=sum*po(j,mod-2);
				sum%=mod;
			}
			ans+=sum;
			ans%=mod;
		}
	}else {
		dfs(0,0);
	} 
	cout<<ans;
	return 0;
}
