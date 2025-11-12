#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,a[N],xr[N],pre[N],dp[N];
map<int,vector<int>>la;
bool ch[N];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	xr[0]=0;
	for(int i=1;i<=n;i++){
		xr[i]=xr[i-1]^a[i];
		la[xr[i]].push_back(i);
	}
	for(int i=n;i>0;i--){
		int nd=k^xr[i];
		if(la[nd].size()){
			int l=0,r=la[nd].size()-1;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(la[nd][mid]<i)l=mid;
				else r=mid-1;
			}
			pre[i]=la[nd][l];
			if(pre[i]>=i)pre[i]=n+1;
		}
		else pre[i]=n+1;
		//cout<<i<<" "<<pre[i]<<endl;
	}
	dp[n+1]=-1;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[pre[i]]+1);
		//cout<<dp[i]<<" ";
	}
	//cout<<endl;
	printf("%d",dp[n]);
	return 0;
}
