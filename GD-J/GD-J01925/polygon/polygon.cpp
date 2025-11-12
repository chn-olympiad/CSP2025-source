#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,mod=998244353;
long long n,a[maxn],cnt;
void dfs(long long x,long long sum,long long Max){
	if(x==n+1){
		if(sum>Max*2)cnt=(cnt+1)%mod;
		return;
	}
	dfs(x+1,sum,Max);
	dfs(x+1,sum+a[x],max(Max,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<cnt<<'\n';
	return 0;
}
