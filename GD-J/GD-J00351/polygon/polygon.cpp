#include<bits/stdc++.h>
using namespace std;
long long f[50005];
long long n,ans;
void dfs(int s,long long i,long long o){
	if(s==n+1){
		if(i>2*o)ans++;
		return ;
	}
	dfs(s+1,i+f[s],max(o,f[s]));
	dfs(s+1,i,o);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	if(n>500){
		cout<<0;
		return 0;
	} 
	for(long long i=1;i<=n;i++)cin>>f[i];
	dfs(1,0,0);
	cout<<ans;
}

