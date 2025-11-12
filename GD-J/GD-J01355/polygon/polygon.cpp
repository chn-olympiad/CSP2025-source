#include<bits/stdc++.h>
using namespace std;
long long a[5005],ans,n,p[5005];
void dfs(long long d,long long maxa,long long sum,long long s){
	if(d>=3&&maxa*2<sum){
		ans++;
	} 
	if(d==n+1)return ;
	for(int i=s;i<=n;i++){
		if(p[i]==0){
			p[i]=1;
			dfs(d+1,max(maxa,a[i]),sum+a[i],i);
			p[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%lld",ans/2);
	return 0;
}
/*
5
2 2 3 8 10
*/
