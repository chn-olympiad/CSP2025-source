#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=0;
int a[1086][1086];
int x[100086],y[100086],w[100086];
int book[100086];
bool pd(){
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			return 0;
		}
	}
	return 1;
}
void dfs(int xxx){
	if(pd()){
		ans++;
	}
	for(int i=xxx;i<=m;i++){
		book[x[i]]++,book[y[i]]++;
		dfs(i);
		book[x[i]]--,book[y[i]]--;
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
		book[x[i]]++,book[y[i]]++;
		dfs(i);
		book[x[i]]--,book[y[i]]--;
	}
	cout<<ans;
	return 0;
}
