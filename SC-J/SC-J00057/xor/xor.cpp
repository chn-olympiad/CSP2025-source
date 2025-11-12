#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005],s[500005];
unordered_map<int,vector<int>>mp;
int dp[500005],f[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	mp[s[1]].push_back(1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	int now=1;
	while(now<=n){
		int num=k^s[now-1];
		if(mp[num].size()==0){
			f[now]=-1;
			now++;
			continue;
		}
		int l=0,r=mp[num].size()-1,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(mp[num][mid]>=now){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		f[now]=(ans==-1?-1:mp[num][ans]);
		now++;
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		if(f[i]!=-1){
			dp[f[i]]=max(dp[f[i]],dp[i-1]+1);
		}
	}
	int cc=0;
	for(int i=1;i<=n;i++){
		cc=max(cc,dp[i]);
	}
	cout<<cc<<endl;
	return 0;
}