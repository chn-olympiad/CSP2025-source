#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
bool cheak=true;
int a[5001],c[5001],n,ans;
void C(){
	c[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=1;
		for(int j=i-1;j>=1;j--){
			c[j]+=c[j-1];
			c[j]%=MOD;
		}
	}
}
bool cmp(int x,int y){
	return x<y;
}
void dfs(int st,int sum,int mx,int b){
	if(st>n){
		if(b>=3){
			if(sum>a[mx]*2) ans++;
		}
		return;
	}
	dfs(st+1,sum,mx,b);
	dfs(st+1,sum+a[st],st,b+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			cheak=false;
		}
	}
	if(cheak){
		C();
		for(int i=3;i<=n;i++){
			ans+=c[i];
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
