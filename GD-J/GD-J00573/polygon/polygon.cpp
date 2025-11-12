#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans,b[5005];
ll sum;
bool vis[5005];
void dfs(int m,int x,int j){
	if(x>m){
		sum=0;
		for(int i=1;i<=m;i++){
			sum+=b[i];
		}
		if(sum>b[m]*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=j;i<=n;i++){
		if(vis[i]==0){
			b[x]=a[i];
			vis[i]=1;
			dfs(m,x+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1,1);
	}
	cout<<ans;
	return 0;
}

