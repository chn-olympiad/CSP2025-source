#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,ans,a[5010],h[5010],w[5010];
bool v[5010];
void dfs(int x,int s,int mx,int c){
	if(s+h[x]<=mx*2)return;
	if(x>n&&s>mx*2){
		ans=(ans+1)%p;
		return;
	}
	v[x]=1;
	dfs(x+1,s+a[x],max(mx,a[x]),c+1);
	v[x]=0;
	dfs(x+1,s,mx,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mmxx=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)mmxx=max(mmxx,a[i]);
	for(int i=1;i<=n;i++)
	if(mmxx==1){
		w[0]=1;
		for(int i=1;i<=n;i++)w[i]=w[i-1]*2ll%p;
		cout<<((1<<n)-1-n-n*(n-1)/2+p)%p;
		return 0;
	}
	for(int i=n;i>=1;i--)h[i]=h[i+1]+a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
