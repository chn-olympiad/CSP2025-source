#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a[500005],maxcen;

void dfs(int l,int cen){
	if(l>n){
		maxcen=max(maxcen,cen);
		return;
	}
	for(;l<=n;l++){
		int pan=0;
		for(int r=l;r<=n;r++){
			pan^=a[r];
			if(pan==k)dfs(r+1,cen+1);
		}
	}
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0);
	cout<<maxcen;
	return 0;
}
