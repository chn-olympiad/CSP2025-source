#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn;
long long cnt;
void dfs(int maxn,long long sum,int pos){
	if(sum>2*maxn) cnt=(cnt+1)%998244353;
	for(int i=pos+1;i<=n;i++) dfs(max(maxn,a[i]),sum+a[i],i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}

