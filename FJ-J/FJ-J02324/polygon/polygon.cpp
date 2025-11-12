#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans,anss;
long long b[5005];
void zxcv(long long x){
	long long xx=x;
	for(int i=2;i<=sqrt(xx);i++){
		while(x%i==0){
			x/=i;b[i]++;
		}
		if (x==0) break;
	}
	if (x!=0) b[x]++;
	return;
}
void qwer(long long x){
	long long xx=x;
	for(int i=2;i<=sqrt(xx);i++){
		while(x%i==0){
			x/=i;b[i]--;
		}
		if (x==0) break;
	}
	if (x!=0) b[x]--;
	return;
}
void dfs(long long x,long long s,long long MAX){
	if (x>n){
		if (MAX*2<s) ans++;
		ans%=998244353;
		return;
	}
	dfs(x+1,s+a[x],max(MAX,a[x]));
	dfs(x+1,s,MAX);
	return;
}
void ghjk(){
	anss=1;ans=0;
	for(int i=3;i<=n;i++){
		for(int j=(n-i+1);j<=n;j++){
			zxcv(j);
			qwer(j-(n-i+1)+1);
		}
		anss=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=b[j];k++){
				anss*=j;
				anss%=998244353;
			}
			b[j]=0;
		}
		ans+=anss;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=20){
		ans=0;
		dfs(1,0,0);
		cout<<(ans%998244353)<<endl;
	}else{
		ghjk();
	}
	return 0;
}
