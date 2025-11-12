#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],ans,b[100006];
void dfs(int now,int si,int maxx,int he){
	if(si==0){
		if(maxx*2<he){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i = now;i<=n-si+1;i++){
		dfs(i+1,si-1,max(maxx,a[i]),he+a[i]);
	}
}
int A(int x,int y){
	int er=1;
	for(int i = x,j=1;j<=y;j++,i--){
		er*=i;
		er%=998244353;
	}
	return er;
}
int jie(int x){
	int er=1;
	for(int i = 1;i<=x;i++){
		er*=i;
		er%=998244353;
	}
	return er;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i = 3;i<=n;i++){
			for(int j=3;j<=i;j++){
				ans+=A(i-1,j-1)/jie(j-1);
				ans%=998244353;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i = 3;i<=n;i++){
			dfs(1,i,0,0);
		}
		cout<<ans;
		return 0;
	}
}
