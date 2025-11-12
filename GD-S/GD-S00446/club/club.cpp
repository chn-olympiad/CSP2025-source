#include<bits/stdc++.h> 
using namespace std;
struct node{
	int x,y,z;
};
int main(){
	ifstream in("club.in");
	ofstream out("club.out");
	int t;
	in>>t;
	for(int q=0;q<t;q++){
		int n;
		in>>n;
		vector<node> v(n);
		vector<vector<vector<int> > > dp(n/2+1,vector<vector<int> >(n/2+1,vector<int>(n/2+1,0)));
		int ans=0;
		for(int i=0;i<n;i++){
			in>>v[i].x>>v[i].y>>v[i].z;
			for(int a=0;a<=i&&a<=n/2;a++){
				for(int b=0;a+b<=i&&b<=n/2;b++){
					int c=i-a-b;
					if(c>n/2){
						continue;
					}
					if(a<n/2){
						dp[a+1][b][c]=max(dp[a][b][c]+v[i].x,dp[a+1][b][c]);
						ans=max(ans,dp[a+1][b][c]);
					}
					if(b<n/2){
						dp[a][b+1][c]=max(dp[a][b][c]+v[i].y,dp[a][b+1][c]);
						ans=max(ans,dp[a][b+1][c]);
					}
					if(c<n/2){
						dp[a][b][c+1]=max(dp[a][b][c]+v[i].z,dp[a][b][c+1]);
						ans=max(ans,dp[a][b][c+1]);
					}
				}
			}
		}
		out<<ans<<'\n';
	}
	return 0;
}
