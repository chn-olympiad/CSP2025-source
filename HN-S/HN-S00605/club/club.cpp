#include<bits/stdc++.h>
using namespace std;
int maxn,d1[205],d2[205],d3[205],n;
void dfs(int k,int c1,int c2,int c3,int ans){
	if(c1>n/2||c2>n/2||c3>n/2) return;
	if(k==n+1){
		maxn=max(ans,maxn);
		return;
	}
	dfs(k+1,c1+1,c2,c3,ans+d1[k]);
	dfs(k+1,c1,c2+1,c3,ans+d2[k]);
	dfs(k+1,c1,c2,c3+1,ans+d3[k]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d1[i]>>d2[i]>>d3[i];
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
		maxn=0;
	}
	return 0;
}
