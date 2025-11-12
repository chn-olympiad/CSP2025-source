#include<bits/stdc++.h>
using namespace std;
int const Maxn=5e5+5;
int n,k;
int a[Maxn];
int maxn;
void dfs(int c,int cnt,int h){
	if(c==n){
		if(h==k)cnt++;
		maxn=max(cnt,maxn);
		return;
	}
	for(int i=c+1;i<=n;i++){
		if(h==k){
			dfs(i,cnt+1,a[i]);
		}
		dfs(i,cnt,a[i]);
		dfs(i,cnt,h^a[i]);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,a[1]);
	cout<<maxn;
	return 0;
}