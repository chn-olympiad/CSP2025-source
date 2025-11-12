#include<bits/stdc++.h>
using namespace std;
long long ans;
int num[5100],n;
void dfs(int x,int mx,int step,int sum){
	mx=max(num[x],mx);
	sum+=num[x];
	if(step>=3)
		if(sum>2*mx) ans++;
	for(int i=x+1;i<=n;i++)
		dfs(i,mx,step+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	dfs(0,0,1,0);
	ans%=998244353;
	cout<<ans;
	return 0;
} 
