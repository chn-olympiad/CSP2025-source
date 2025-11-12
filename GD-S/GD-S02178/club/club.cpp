#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[3][N],ma,n;
void dfs(int idx,int sum,int c1,int c2,int c3){
	if(c1>n/2||c2>n/2||c3>n/2)return;
	if(idx==n+1){
		ma=max(ma,sum);
		return;
	}
	dfs(idx+1,sum+a[0][idx],c1+1,c2,c3);
	dfs(idx+1,sum+a[1][idx],c1,c2+1,c3);
	dfs(idx+1,sum+a[2][idx],c1,c2,c3+1);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[0][i]>>a[1][i]>>a[2][i];
		ma=0;
		dfs(1,0,0,0,0);
		cout<<ma<<"\n";
	}
}
