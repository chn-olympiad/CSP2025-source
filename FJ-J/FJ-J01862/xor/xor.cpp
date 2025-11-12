#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+25,M=(1<<20)+4436;
ll n,k,a[N],dp[N],ans,x[N],pos[M];
vector<pair<int,int>> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	x[i]=x[i-1]^a[i];
	}
	for(int i=0;i<=(1<<20);i++) pos[i]=-1;
	pos[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		ll cnt=x[i]^k;
		if(pos[cnt]!=-1) dp[i]=max(dp[i],dp[pos[cnt]]+1);
		pos[x[i]]=i;
	}
	cout<<dp[n];
    return 0;
}
