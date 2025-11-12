#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN],n,ans;
void dfs(int step,int sum,int maxn,int num){
	if(step>n){
		if(num>=3){
			if(sum>2*maxn) ans=(ans+1)%998244353;
		}
		return;
	} 
	dfs(step+1,sum+a[step],max(maxn,a[step]),num+1);
	dfs(step+1,sum,maxn,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 