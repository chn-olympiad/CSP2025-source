#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],cnt=0;
void dfs(int i,int maxn,int sum,int step){
	if(i==n+1){
		if(step>=3&&sum>2*maxn)cnt++;
		return;
	}
	dfs(i+1,max(maxn,a[i+1]),sum+a[i+1],step+1);
	dfs(i+1,maxn,sum,step);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<cnt/2;
	return 0;
}
