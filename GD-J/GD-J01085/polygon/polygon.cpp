#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050;
const int MOD=998244353;
int n,a[N],qzh[N];
bool flag=1;
int c(int x,int y){
	int d=1,s=1;
	for(int i=x;i>=(x-y+1);i--){
		d*=i;
		d%=MOD;
	}
	for(int i=1;i<=y;i++){
		s*=i;
		s%=MOD;
	}
	return d/s;
}
int dfs(int dq,int s,int d,int d1,int p){
	if(dq>d1){
		if(s>d&&p>=2) return 1;
		return 0;
	}
	return dfs(dq+1,s,d,d1,p)+dfs(dq+1,s+a[dq],d,d1,p+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	sort(a+1,a+n+1);
//	if(n==3){
//		if(a[1]+a[2]+a[3]>2*a[3]){
//			cout<<1;
//			return 0;
//		}
//		cout<<0;
//		return 0;
//	}
//	cout<<"2";
	int ans=0;
	if(flag){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]*2>=qzh[i]){
			continue ;
		}
		ans+=dfs(1,0,a[i],i-1,0)%MOD;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
