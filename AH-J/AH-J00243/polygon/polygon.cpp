#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans,ds[1000005];
void dfs(long long dep,long long p,long long sum,long long chance,long long biggest){
	if (dep==n+1){
	if (chance==p){
		if (sum>biggest*2){
			ans++;
		}
		return ;
	}
	return ;
	}
	if (chance==p){
		if (sum>biggest*2)
			ans++;
		return ;
	}
	if (chance<p){
		ds[chance+1]=a[dep];
		dfs(dep+1,p,sum+a[dep],chance+1,a[dep]);
		}
	dfs(dep+1,p,sum,chance,biggest);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++){
		dfs(1,i,0,0,0);
	}
	cout<<ans;
return 0;
}
