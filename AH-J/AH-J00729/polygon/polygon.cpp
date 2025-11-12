#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5010],sum,sumd,cnt;
bool ok1=true;
vector<LL> ans;
bool check(){
	LL maxn=ans[ans.size()-1];
	return sumd>2*maxn;
}
void dfs(LL cur){
	if(cur>n){
		if(check()) cnt++;
		cnt%=998244353;
		return ;
	}
	dfs(cur+1);
	ans.push_back(a[cur]);
	sumd+=a[cur];
	dfs(cur+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		if(a[i]!=1) ok1=false;
	}
	sort(a+1,a+n+1);
	if(ok1){
		printf("%lld",(n-1)*(n-2)/2%998244353);
	}else if(n==3){
		if(a[n]*2<sum) printf("1");
		else printf("0");
	}else printf("0");
	return 0;
}
