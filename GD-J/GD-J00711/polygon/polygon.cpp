#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],n,t,ans;
void dfs(int x){
	if(x==n+1){
		if(t==0)return;
		int q=0,maxn=0;
		for(int i=1;i<=t;i++){
			q+=b[i];
			maxn=max(b[i],maxn);
		}
		if(q>2*maxn)ans++;
		return;
	}
	t++;
	b[t]=a[x];
	dfs(x+1);
	t--;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
