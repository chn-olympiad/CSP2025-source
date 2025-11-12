#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005][5005],bj,ans,book[5005];
void dfs(int x,int gs,int Max,int s){
	if(gs>=3&&book[x-1]){
		if(s>Max*2){
			ans++;
		}
	}
	if(x>=n+1) return ;
	book[x]=1;
	dfs(x+1,gs+1,max(Max,a[x]),s+a[x]);
	book[x]=0;
	dfs(x+1,gs,Max,s);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=1) bj=1;
		for(int j=1;j<i;j++) sum[j][a[i]]++;
	}
	if(!bj){
		cout<<((n-1)*(n-2)/2);
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}