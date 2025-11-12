#include<bits/stdc++.h>
using namespace std;

int n,k;
int nu[500001];
vector<bool> dp[500001];
int dp1[500001];
int ge(int x,int y){
	return dp[x][y-x+1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>nu[i];
	for(int i=1;i<=n;i++){
		int ca=0;
		dp[i].push_back(0);
		for(int j=i;j<=n;j++){
			ca^=nu[j];
			dp[i].push_back((ca==k));
		}
	}
	dp1[1]=dp[1][1];
	int lt=1;
	for(int i=2;i<=n;i++){
		if(ge(lt,i-1)==0){
			dp1[i]=dp1[i-1]+ge(lt,i);
		}
		else{
			dp1[i]=dp1[i-1]+ge(i,i);
			lt=i;
		}
	}
	cout<<dp1[n];
}
