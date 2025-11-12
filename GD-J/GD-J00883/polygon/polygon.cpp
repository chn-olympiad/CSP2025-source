#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,ma,anss,la,t,a[20000800],b[20000800],p[20000800],ans[20000800],mod=998244353;
string s;
void dfs(int x,int l){
	if(x==n+1){
		ma=ans[1];
	//	cout<<l<<" "<<k<<"\n";
		for(int i=1;i<=k;i++){
			//cout<<ans[i]<<" ";
			ma=max(ans[i],ma);
		}
		//cout<<"\n";
		if(l>ma*2) anss++;
		anss%=mod;
	}
	else{
		dfs(x+1,l);
		ans[++k]=a[x];
		dfs(x+1,l+a[x]);
		ans[k--]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<anss;
}
