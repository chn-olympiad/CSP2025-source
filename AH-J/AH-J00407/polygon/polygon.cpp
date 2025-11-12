#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ma;
int bad_ans;
int dfs(int k,int s,int m){
	if(k==n+1){
		if(s>2*m) return 1;
		return 0;
	}
	int d1=dfs(k+1,s,m);
	int d2=dfs(k+1,s+a[k],max(m,a[k]));
	return (d1+d2)%MOD;
}
int ksm(int a,int p,int m){
	int s=a,ans=1;
	while(p){
		if(p&1) ans=ans*s%m;
		s=s*s%m;
		p/=2;
	}
	return ans;
}
bool tepan(){
	if(ma>1) return 0;
	int s=ksm(2,n,MOD);
	int c0=1;
	int c1=n;
	int c2=n*(n-1)/2;
	cout<<(s-c0-c1-c2+MOD)%MOD;
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(tepan()) return 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+a[j]>2*max(a[i],a[j])) bad_ans++;
		}
	}
	cout<<dfs(1,0,0)-bad_ans;
	return 0;
}
