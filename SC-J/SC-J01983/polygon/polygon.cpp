#include<bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int n,gsa=0;
long long a[114514];
void dfs(long long bs,long long ans,int p){
	if(bs>n){
		return ;
	}
	for(int i=p+1;i<=n;i++){
		ans+=a[i];
		dfs(bs+1,ans,i);
		ans-=a[i];
	}if(bs>=3&&ans>a[p]*2){
		gsa++;
		gsa%=MOD;
		return ;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<gsa%MOD;
	return 0;
}