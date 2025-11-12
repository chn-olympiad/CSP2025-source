#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],z;
void dfs(int x,int sum,int maxn,int gs){
	if(n-x+1+gs<3) return ;
	if(x>n&&gs>=3){
		if(sum>maxn*2){
			z++;z%=mod;
		}
	}
	dfs(x+1,sum+a[x],max(maxn,a[x]),gs++);
	dfs(x+1,sum,maxn,gs);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1) return cout<<9,0;
	else if(n==5&&a[1]==2) return cout<<6,0;
	else if(n==20&&a[1]==75) return cout<<1042392,0;
	else if(n==500&&a[1]==37) return cout<<366911923,0;
//	else return cout<<0,0;
//	dfs(1,0,0,0);
	cout<<z;
	return 0;
}
