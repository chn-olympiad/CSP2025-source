#include<bits/stdc++.h>
using namespace std;
long long n,l[5001],con;
void dfs(long long i,long long j,long long sum,long long maxx){
	sum+=l[i];
	maxx=max(maxx,l[i]);
	j++;
	if(sum>maxx*2&&j>=3){
		con++;
		con%=998244353;
	}
	for(long long k=i+1;k<=n;k++){
		dfs(k,j,sum,maxx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>l[i];
	}
	for(long long i=1;i<=n;i++){
		dfs(i,0,0,0);
	}
	con%=998244353;
	cout<<con;
}