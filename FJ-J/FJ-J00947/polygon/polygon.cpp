#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,s[5005];
ll ans,maxn=998244353;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int ad,int mx,int nm){
	if(ad>2*mx){
		ans++;
	}
	for(int i=nm+1;i<=n;i++)
		dfs(ad+s[i],max(mx,s[i]),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	sort(s+1,s+n+1,cmp);
	dfs(0,0,0);
	printf("%lld\n",ans%maxn);
	return 0;
}
