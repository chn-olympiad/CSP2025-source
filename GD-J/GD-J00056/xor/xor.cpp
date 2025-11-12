#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
int n,k,a[114514*5],b[114514*5],c[114514*5],dp[114514*5];
vector<int> v[114514*5];
int gethalf(int bi,int l,int r,int num){
	while(l<r-1){
		int mid=(l+r)/2;
		if(v[bi][mid]<=num) l=mid;
		else r=mid-1;
	}
	return (v[bi][r]<=num ? v[bi][r]:v[bi][l]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]^a[i],v[b[i]].push_back(i);
	for(int i=1;i<=n;i++) b[i]^=k;
	for(int i=1;i<=n;i++) if(v[b[i]].size()&&v[b[i]][0]<=i){
		c[i]=gethalf(b[i],0,v[b[i]].size()-1,i);
//		cout<<b[i]<<' '<<0<<' '<<v[b[i]].size()-1<<' '<<i<<' '<<gethalf(b[i],0,v[b[i]].size()-1,i)<<endl;
	}
	elif(b[i]==0) c[i]=0;
	else c[i]=-1;
	for(int i=1;i<=n;i++) if(c[i]==-1) dp[i]=dp[i-1];
	else dp[i]=max(dp[i-1],dp[c[i]]+1);
//	for(int i=0;i<=n;i++) cout<<b[i]<<' '<<c[i]<<' '<<dp[i]<<endl;
	cout<<dp[n];
	return 0;
}//#Shang4Shan3Ruo6Shui4
//4 3 2 1 0 3
