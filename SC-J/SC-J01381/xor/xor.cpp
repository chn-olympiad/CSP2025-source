#include<bits/stdc++.h>
using namespace std;
int n,k;
int num,qz[500500],qj[500500],dp[500500];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	int xx=4^5;
//	cout<<xx<<endl;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		int jj;
		cin>>jj;
		qz[i]=qz[i-1]^jj;
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int ii=i-1;
			int iii=qz[ii]^qz[j];
//			cout<<'!'<<qz[ii]<<' '<<qz[j]<<' '<<iii<<endl;
			if(iii==k){
				qj[i]=j;
				break;
			}
		}
	}
//	for(int i=1; i<=n; i++){
//		cout<<qj[i]<<' ';
//	}
//	cout<<endl;
//	cout<<"  !!!"<<endl;
	for(int i=1; i<=n+1; i++){
		dp[i]=max(dp[i-1],dp[i]);
		if(qj[i]!=0){
			dp[qj[i]+1]=max(dp[qj[i]+1],dp[i]+1);
		}
//		cout<<dp[i]<<' '<<qj[i]<<endl;
	}
	cout<<dp[n+1];
	return 0;
}