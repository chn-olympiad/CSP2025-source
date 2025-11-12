#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500001],lst[500001],dp[500001];
vector<pair<int,int> > f;int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f.push_back({i,0});
		for(int j=cnt;j<f.size();j++){
			f[j].second^=a[i];
			if(f[j].second==k){
				lst[i]=f[j].first;
				cnt=lst[i];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<lst[i]<<" ";
//	}
//	cout<<endl;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(lst[i]!=0){
			dp[i]=max(dp[i],dp[lst[i]-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}

