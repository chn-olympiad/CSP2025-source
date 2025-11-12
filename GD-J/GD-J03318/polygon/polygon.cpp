#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],maxx,ans,per[5001];
void dfs(int n,int sum,int al,int ind){
	if(al==n){
		maxx=0;
		for(int i=1;i<=al;i++) maxx=max(maxx,per[i]);
		maxx<<=1;
		if(sum>maxx){
			ans++;
			ans%=mod;
		}return ;
	}if(ind>::n) return ;
	per[al+1]=a[ind];
	dfs(n,sum+a[ind],al+1,ind+1);
	dfs(n,sum,al,ind+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=3;i<=n;i++) dfs(i,0,0,1);
	cout<<ans;
	return 0;
}
