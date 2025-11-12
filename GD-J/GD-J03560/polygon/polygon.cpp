#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],s[10001],ans,p,x,cnt,m;
bool pp=0;
void dfs(int i,int sum,int s){
	if(i==m){
		if(sum<=cnt&&s<=p) {
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(i+1,sum,s);
	dfs(i+1,sum+=a[i],s+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>1) pp=1;
	}
	sort(a+1,a+1+n);
	if(pp==0){
		for(int i=3;i<=n;i++) {
			long long s=1;
			for(int j=n;j<=n-i+1;j--) {
				s*=j;
				s%=998244353;
			}
			ans+=s;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++){
		p=i-3;
		if(s[i]<=a[i]*2) continue;
		cnt=s[i]-(a[i]*2)-1;
		m=i;
		dfs(1,0,0);
	}
	cout<<ans%998244353;
}
