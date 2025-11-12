#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],s[5005],maxn,cnt,vis[5005],ans[5005]; 
int g(int n,int m){
	int c=1,d=1;
	for(int i=n;i>=n-m+1;i--){
		c*=i;
	//	c%=998244353;
	}
	for(int j=m;j>=1;j--){
		d*=j;
		//d%=998244353;
	}
	return c/d;
}
void dfs(int cs,int p,int x){
	if(cs==x){
		int an=0;
		for(int i=1;i<=x;i++)an+=a[ans[i]];
		if(an>a[ans[x]]*2){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=p+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ans[cs+1]=i;
		dfs(cs+1,i,x);
		vis[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxn==1){
		for(int i=3;i<=n;i++){
			cnt+=g(n,i);
			cnt%=998244353;
		}
		cout<<cnt<<" ";
	}else{
		for(int i=3;i<=n;i++){
			dfs(0,0,i);
		}
		cout<<cnt;
	}
	return 0;
}
