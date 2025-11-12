#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("xor.in");
	ofstream out("xor.out");
	int n,k;
	in>>n>>k;
	vector<int> dp(n+1,0);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		in>>a[i];
	}
	for(int i=0;i<n;i++){
		int cnt=0,j;
		for(j=i;j<n;j++){
			cnt^=a[j];
			if(cnt==k){
				break;
			} 
		}
		if(cnt==k){
			for(j+=1;j<=n;j++){
				if(dp[j]>=dp[i]+1){
					break;
				}
				dp[j]=dp[i]+1;
			}
		}
	}
	out<<dp[n];
	return 0;
}
