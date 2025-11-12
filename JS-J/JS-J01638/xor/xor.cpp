#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int s[500010];
int dp[500010];
struct node{
	int l,r;
};
vector<node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=abs(s[j]-s[i-1]);
			if(t==k){
				v.push_back({i,j});
				break;
			}
		}
	}
	int ans=0;
	int n=v.size();
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=i-1;j>=0;j--){
			if(v[j].r<v[i].l) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
