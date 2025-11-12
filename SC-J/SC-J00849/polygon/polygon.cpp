#include<bits/stdc++.h>
using namespace std;
long long N=998244353;
int a[6000];
bool b[6000];
long long js;
int n;
int dfs(int zd,int sum,int y,int ans){
	if(sum>2*zd&&ans>=3){
		js++;
		js%=N;
	}
	for(int i=y;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(a[i],sum+a[i],i,ans+1);
			b[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(0,0,1,0);
	printf("%lld",js);
	return 0;
}

