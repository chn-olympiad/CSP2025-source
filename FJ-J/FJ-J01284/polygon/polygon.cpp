#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt=0;
long long mod=998244353;
void dfs(long long sum,long long maxx,int gs,int o){
	if(sum>maxx*2 and gs>=3){
		cnt++;
		cnt=cnt%mod;
	}
	if(gs>n)return ;
	for(int i=o+1;i<=n;i++){
		long long h=max(maxx,a[i]);
		dfs(sum+a[i],h,gs+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cnt=cnt%mod;
	cout<<cnt<<"\n";
	return 0;
}
