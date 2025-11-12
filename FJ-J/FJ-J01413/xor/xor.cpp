#include<bits/stdc++.h>
using namespace std;
int num[1100005];
int k,dp[500005],n[500005],nl,z[500005],m[500005],ma[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>nl>>k;
	//for(int i=0;i<1100005;i++) num[i].push_down(0);
	for(int i=1;i<=nl;i++){
		cin>>n[i];
	//	cout<<n[i]<<' ';
	}
//	cout<<endl;
	m[1]=n[1];
	for(int i=2;i<=nl;i++){
		m[i]=m[i-1]^n[i];
	}
	for(int i=1;i<=nl;i++){
	//	cout<<num[(m[i]^k)]<<endl;
		if(n[i]==k){
			z[i]=i;
			num[m[i]]=i;
			continue;
		}
		if(num[(m[i]^k)]==0){
			if((m[i]^k)==0){
				z[i]=1;
				num[m[i]]=i;
				continue;
			}
			z[i]=-1;
			num[m[i]]=i;
			continue;
		}
		z[i]=num[(m[i]^k)]+1;
		num[m[i]]=i;
	}
	for(int i=1;i<=nl;i++){
		if(z[i]==-1) dp[i]=dp[i-1];
		else{
			dp[i]=ma[z[i]-1]+1;
		}
		dp[i]=max(dp[i],dp[i-1]);
		ma[i]=max(ma[i-1],dp[i]);
	}
	cout<<dp[nl]<<endl;
//	for(int i=1;i<=nl;i++) cout<<z[i]<<' '; 
	return 0;//11:02ÇÐ 
}
