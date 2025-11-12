#include<bits/stdc++.h>
using namespace std;
int n,k,uc;
int a[500001];
int pre[500001];
struct lr{
	int l;
	int r;
}cnt[800001];
bool cmp(lr c,lr d){
	return c.r<d.r;
}
int dp[500001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(int(pre[j]^pre[i-1])==k){
				cnt[++uc]={i,j};
			}
		}
	}
	for(int i=1;i<=uc;i++)dp[i]=1;
	for(int i=1;i<=uc;i++){
		for(int j=1;j<=uc;j++){
			if(cnt[i].l>cnt[j].r)dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=uc;i++){
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
}