#include<iostream>
#include<vector>
//#include<pair>
#include<cmath>
using namespace std;

int n,k,cnt=0;
int dfs(const vector<vector<bool>> &dp,const vector<pair<int,int>> &wrs1,vector<vector<int>> &solve,int sum,int limit){
	if(limit>n) return sum;
	int res=sum;
	for(int k=0;k<wrs1.size();k++){
		int i=wrs1[k].first,j=wrs1[k].second;
		if(i>limit){
			//cout<<i<<" "<<j<<endl;
			if(solve[i][j]){
				res=max(res,solve[i][j]);
			}
			else{
				solve[i][j]=dfs(dp,wrs1,solve,sum+1,j);
				res=max(res,solve[i][j]);
			}
		}
	}
//	for(int i=limit+1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(dp[i][j]){
//				
//			}
//		}
//	}
	return res;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<int> a(n+2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<pair<int,int>> wrs1;
	vector<vector<bool>> dp(n+2,vector<bool>(n+2,false));
	for(int i=1;i<=n;i++){
		int crt=0;
		for(int j=i;j<=n;j++){
			crt^=a[j];
			if(crt==k){
				dp[i][j]=1;
				wrs1.push_back(pair<int,int>(i,j));
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	vector<vector<int>> solve(n+2,vector<int>(n+2,0));
	cout<<dfs(dp,wrs1,solve,0,0)<<endl;
	return 0;
}
