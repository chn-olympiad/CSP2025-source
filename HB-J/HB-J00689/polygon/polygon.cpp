#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans,mod=998244353;
int check(){
	int num=0,maxn=0,len=0;
	for(int i=1;i<=n;i++){
		if(!sum[i]){
			maxn=max(maxn,a[i]);
			len+=a[i];
			num++;
		}
	}
	if(num<3) return 0;
	return len>maxn*2;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i=0;i<=1;i++){
		sum[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

