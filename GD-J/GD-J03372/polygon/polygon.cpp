#include<bits/stdc++.h>
using namespace std;
int es[10005];
long long n,i,ans;
void dfs(int dep,long long sum,int nn,int maxx){
	if(dep==i){
		if(sum>maxx*2){
			ans++;
			return;
		}
	}
	if(nn>n){
		return;
	}
	dfs(dep,sum,nn+1,maxx);
	dfs(dep+1,sum+es[nn],nn+1,max(maxx,es[nn]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>n;
	for(int qwq=1;qwq<=n;qwq++){
		cin>>es[qwq];
	}
	for(i=3;i<=n;i++){
		dfs(0,0,1,-1);
	}
	cout<<ans%998244353;

	return 0;
}
