#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,ans,a[500005],b[500005];

bool cheak(int i,int j,int l,int r){
	if(i<=l&&j>=l) return 0;
	if(i<=r&&j>=r) return 0;
	return 1;
}
void dfs(int m,int l,int r,bool f){
	if(!f){
		ans=max(ans,m-1);
		return;
	}
	for(int i=r;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j]^b[i-1]==k)
				dfs(m+1,i,j,cheak(i,j,l,r));
		}
	}
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	dfs(0,0,0,1);
	printf("\n%lld",ans);
	return 0;
}