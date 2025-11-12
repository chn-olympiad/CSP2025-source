#include <bits/stdc++.h>
using namespace std;

int n,ans=0,cnt=0;
int a[5001];

int c(int,int);
void dfs(int,int,int,int,int);

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			(ans+=c(n,i))%=988244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++)
			ans+=a[i];
		cout<<(ans>mx*2)<<endl;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
		for(int j=3;i+j-1<=n;j++)
			dfs(1,i,0,0,j);
	cout<<ans<<endl;
	return 0;
}

void dfs(int d,int x,int sum,int maxn,int p){
	if(x>p||(d<p&&n-x<p-1)){
		return;
	}
	maxn=max(maxn,a[x]);
	sum+=a[x];
	if(d<p){
		for(int i=x+1;i<=n;i++)
			dfs(d+1,i,sum,maxn,p);
		return;
	}
	if(sum*2>maxn)
		ans++;
	return;
}

int c(int n,int m){
	int cnt=1;
	for(int i=n-m+1;i<=n;i++)
		(cnt*=i)%=988244353;
	for(int i=1;i<=m;i++)
		(cnt/=i)%=988244353;
	return cnt;
}
