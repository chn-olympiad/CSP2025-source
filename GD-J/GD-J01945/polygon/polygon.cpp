#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
long long a[N],op[N],cnt,n;//dp[i][j]:第i根小木棍能拼成多边形的方案数 
void dfs(int cur){
	if(cur==n+1){
		int summ=0,endi=0,gon=0;
		for(int i=1;i<=n;i++){
			if(op[i]==1){
				summ+=a[i];
				endi=i;
				gon++;
			} 
		}
		if(summ>2*a[endi] && gon>=3){
			cnt++;
			cnt%=mod;
		} 
		return;
	}
	op[cur]=0;
	dfs(cur+1);
	op[cur]=1;
	dfs(cur+1);
}
int main(){
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+1+n);
	dfs(1);
	cout<<cnt;
	return 0;
}
