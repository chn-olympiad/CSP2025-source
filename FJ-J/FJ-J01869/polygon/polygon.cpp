#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
bool vis[5001];
void dfs(long long x,long long h,long long maxx,long long f,long long s){
	if(x>f){
		if(h>maxx){
			ans++;
			//cout<<ans; 
			ans%=998244353;
		}
		return;
	}
	for(int i=s;i<=n-(f-x);i++){
		if(vis[i]==0){
			vis[i]=1;
			if(maxx/2<a[i])dfs(x+1,h+a[i],a[i]*2,f,i);
			else dfs(x+1,h+a[i],maxx,f,i);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	if(a[n]<=1){
		for(int i=3;i<=n;i++){
			int sum=1;
			for(int j=1;j<=i;j++){
				sum*=n-j+1;
			}
			for(int j=1;j<=i;j++){
				sum/=j;
			}
			ans+=sum;
			ans%=998244353;
		}
	}else for(int i=3;i<=n;i++)dfs(1,0,0,i,1);
	cout<<ans;
	return 0;
}
