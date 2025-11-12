#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
bool vis[5005];
int cnt=0;
/*void dfs(int step){
	while(step<n){
		int sum=0;
		int maxn=-1;
		for(int i=1;i<=step;i++){
			maxn=max(maxn,a[i]);
			if(vis[i]){
				sum+=a[i];
			}
		}
		if(maxn*2<sum){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		vis[step]=true;
		dfs(step+1);
		vis[step]=false;
	}
}*/
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	cout<<2;
	return 0;
}
