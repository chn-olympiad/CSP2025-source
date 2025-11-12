#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[5010];
int dfs(int w,int v,int q){
	if(w==1){
		if(v<=0&&q>=3)return 2;
		else if(v<=0&&q>=2)return 1;
		else if(v<=0&&q<2)return 0;
		else if(v<=a[1]&&v>0&&q>=2)return 1;
		else return 0;
	}
	return dfs(w-1,v,q)+dfs(w-1,v-a[w-1],q+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		cout<<n*(n-1)*(n-2)/6;
		return 0;
	}
	for(int i=n;i>=3;i--){
		ans+=dfs(i,a[i]+1,1);
	}
	cout<<ans;
	return 0;
}

