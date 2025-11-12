#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
vector<int>a(N);
vector<int>dp(N,0);
int fun(int begin,int end){
	if(begin==end) return a[begin];
	int s=a[begin];
	for(int i=begin+1;i<=end;i++) s=s^a[i];
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){//begin
	    //dp[i]=dp[i-1];
		for(int j=i;j<=n;j++){//end
			if(fun(i,j)==k){
				dp[j]=max(dp[i-1]+1,dp[j-1]);
			}
		}
	}
	cout<<*max_element(dp.begin(),dp.end());
}
//4 2 2 1 0 3
//4 3 2 1 0 3
//4 0 2 1 0 3

