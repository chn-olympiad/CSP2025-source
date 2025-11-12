#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010];
long long ans=0;
const int mod=998244353;
void dfs(int x,long long s,long long m,int l){
	if(x>n){
		if(s>2*m&&l>=3)
		ans=(ans+1)%mod;
		return;
	}
	if(s+b[x]<=2*m)return;
	dfs(x+1,s+a[x],max(m,a[x]),l+1);
	dfs(x+1,s,m,l);
}
int c(int x,int y){
	int o=1;
	for(int i=x;i>y;i--)
		o*=i;
	return o;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		int s=0;
		for(int i=3;i<=n;i++)
			s+=c(n,i);
		cout<<s;
		return 0;
	}
	b[n]=a[n];
	for(int i=n-1;i>=1;i--)
		b[i]=b[i+1]+a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
