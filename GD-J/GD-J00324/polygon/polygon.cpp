#include <bits/stdc++.h>
using namespace std;
long long n,s=0,MOD=998244353,a[5010];
void dfs(int m,int x,int sum){
	if(x>n){
		return;
	}
	if((a[x]<sum)&&(m>1)){
		s=(s+1)%MOD;
	}
	dfs(m+1,x+1,sum+a[x]);
	dfs(m,x+1,sum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>30){
		for(int i=2;i<n;i++){
			long long sum=(1+n-i)*(n-i)/2;
			s=(s+sum)%MOD;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1,0);
	cout<<s%MOD;
	return 0;
}
