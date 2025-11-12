#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,a[5005],s[5005],ans=0;
bool flag=0;
bool cmp(ll x,ll y){
	return x>y;
}
void dfs(int p,int c,ll sum,ll maxn){
	if (p==n+1){
		if (sum>maxn*2 && c>=3) ans++;
		ans%=mod;
		return;
	}
	dfs(p+1,c+1,sum+a[p],(c==0) ? a[p] : maxn);
	dfs(p+1,c,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		if (a[i]!=1) flag=1;
	}
	sort(a+1,a+1+n,cmp);
	if (n<=3){
		if (n<3 || s[n]<=a[1]*2){
			cout<<0;
		}
		else cout<<1;
		return 0;
	}
	if (flag==0){
		for (int i=1;i<=n-2;i++){
			for (int j=i+1;j<=n-1;j++){
				ans+=pow(2,n-j)-1;
				ans%=mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if (n<=20){
		dfs(1,0,(ll)0,(ll)0);
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n-2;i++){
		int k=i+2;
		for (int j=i+1;j<=n-1;j++){
			if (a[j]>=a[i]){
				ans+=pow(2,n-j)-1;
				ans%=mod;
			}
			while(s[k]-s[j-1]<=a[i] && k<=n) k++;
			if (k>n) break;
			ans+=pow(2,(n-k));
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
