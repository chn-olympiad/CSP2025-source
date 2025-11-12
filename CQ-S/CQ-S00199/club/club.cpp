#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100001][5],s[100001],t[100001],ans;
void dfs(int x){
	if(x>n){
		long long sum=0;
		for(int i=1;i<=n;++i){
			sum+=s[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(t[i]+1>n/2){
			continue;
		}
		++t[i],s[x]=a[x][i];
		dfs(x+1);
		--t[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
				cin>>a[i][j];
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
