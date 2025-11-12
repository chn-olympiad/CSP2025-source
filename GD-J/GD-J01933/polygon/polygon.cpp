#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
long long a[N];
int n;
long long ans=0;
bool vis[N];

void dfs(int x,long long sum,long long m){
	if(x==n+1){
		if(sum>2*m)ans++;
		return;
	}
	dfs(x+1,sum+a[x],max(m,a[x]));
	dfs(x+1,sum,m);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
