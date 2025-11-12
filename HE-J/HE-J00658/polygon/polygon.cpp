#include<bits/stdc++.h>
using namespace std;
int tot;
int w[5020];
int n;

void dfs(int k, int maxn, int sum, int getn){
	if(sum>2*maxn&&getn>=3){
//		cout<<k<<" "<<maxn<<" "<<sum<<" "<<getn<<'\n';
		tot++;
	}
	if(k>n) return;
	dfs(k+1, max(maxn,w[k]), sum+w[k], getn+1);
	dfs(k+1, maxn, sum, getn);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>w[i];
	}
	dfs(0,0,0,0);
	cout<<tot/2;
	return 0;
}
