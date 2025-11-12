#include<bits/stdc++.h>

using namespace std;
int n,o[100005],d[100005],e[100005],ma=-1;
void dfs(int idx,int a,int b,int c,int sum){
	if(idx>n){
		if(a+b+c==n&&a<=n/2&&b<=n/2&&c<=n/2){
			ma=max(ma,sum);
		}
		return;
	}
	dfs(idx+1,a+1,b,c,sum+o[idx]);
	dfs(idx+1,a,b+1,c,sum+d[idx]);
	dfs(idx+1,a,b,c+1,sum+e[idx]);
}
void work(){
	cin>>n;
	for(int i= 1;i<=n;i++){
		cin>>o[i]>>d[i]>>e[i];
	}
	dfs(1,0,0,0,0);
	cout<<ma<<'\n';
	ma=-1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}
