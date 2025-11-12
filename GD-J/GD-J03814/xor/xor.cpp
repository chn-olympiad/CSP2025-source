#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=(1<<21)+50;
int a[N],dp[N],pos[M];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<=(1<<21);i++) pos[i]=-1;
	pos[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		dp[i]=dp[i-1];
		if(pos[(a[i]^k)]!=-1){
			dp[i]=max(dp[i],dp[pos[(a[i]^k)]]+1);
		}
		pos[a[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
