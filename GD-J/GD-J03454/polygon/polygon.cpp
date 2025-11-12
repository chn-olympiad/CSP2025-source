#include<bits/stdc++.h>
using namespace std;
long long a[5001],ans,n;
bool vis[5001];
void dfs(int x,long long now,long long max,long long total){
	if(vis[now]==1){
		return ;
	}
	vis[now]=1;
	if(x==0){
		if(max*2<total){
			ans=ans+1;
		}
		vis[now]=0;
		return ;
	}
	long long m=max;
	for(int i=now;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
		total=total+a[i];
		dfs(x-1,i,max,total);
		max=m;
		total=total-a[i];
	}
	vis[now]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<=n-1;i++){
		for(int j=0;j<n;j++){
			dfs(i,j,a[j],a[j]);
		}
	}
	cout<<(ans%998244353);
	return 0;
}
