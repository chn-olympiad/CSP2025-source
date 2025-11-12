#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[500005],b[500005];
int d[500005],dp[500005],idx1,idx2;
struct f{
	int x,id;
}c[500005];
bool cmp(f xx,f yy){
	if (xx.x==yy.x) return xx.id<yy.id;
	return xx.x<yy.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		c[i].x=b[i];
		c[i].id=i;
	}
	sort(c,c+n+1,cmp);
	for (int i=1;i<=n;i++) d[i]=c[i].x;
	for (int i=1;i<=n;i++){
		x=k^b[i];
		idx1=lower_bound(d,d+n+1,x)-d;
		idx2=upper_bound(d,d+n+1,x)-d;
		idx2--;
		dp[i]=dp[i-1];
		for (int j=idx1;j<=idx2;j++){
			if (j<0) continue;
			if (c[j].id<i) dp[i]=max(dp[c[j].id]+1,dp[i]);
			else break;
		}
	}
	cout<<dp[n];
	return 0;
}
