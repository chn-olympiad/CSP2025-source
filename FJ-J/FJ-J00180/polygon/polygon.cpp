#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int n;
int a[5010],ans;
int st[5010];
void dfs(int k,int maxx,int sum,int sta){
//	cout<<sta<<endl;
	if(k>n+1) return;
	if(k>3){
		if(sum>maxx*2){
			ans%=998244353;
			ans++;
//			cout<<sum<<endl;
			ans%=998244353;
		}
	}
	for(int i=sta;i<=n;i++){
		dfs(k+1,max(maxx,a[i]),sum+a[i],i+1);
	}		
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,-INF,0,1);
	cout<<ans;
	return 0;
}
