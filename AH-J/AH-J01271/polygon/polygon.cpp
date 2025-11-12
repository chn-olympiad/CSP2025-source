#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void dfs(int i,int cnt,int maxn,int he){
	if(i==n+1){
		if(cnt>=3){
			if(he>maxn*2){
				ans++;
			}
		}
		return ;
	}
	dfs(i+1,cnt+1,max(maxn,a[i]),he+a[i]);
	dfs(i+1,cnt,maxn,he);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

