#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[500005],n,ans;
void dfs(int p,int d,int i){
	if(d>=3&&p>2*a[i])ans++,ans%=mod;
	if(i>n)return;
	for(int j=i+1;j<=n;j++){
		if(d<2&&j>n-2+d)break;
		dfs(p+a[j],d+1,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
}