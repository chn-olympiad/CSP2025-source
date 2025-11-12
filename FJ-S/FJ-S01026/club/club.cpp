#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define int long long
vector<vector<int> > a;
vector<vector<vector<int> > >dpp;
//vector<vector<vector<vector<int> > > > dp;
int n,T;
long long dp[40][25][25][25];
long long dfs(int deep,int w1,int w2,int w3){
	if(deep>n)return 0;
	if(dp[deep][w1][w2][w3]!=-1)return dp[deep][w1][w2][w3];
	long long me=dfs(deep+1,w1,w2,w3);
	if(w1+1<=n/2)me=max(dfs(deep+1,w1+1,w2,w3)+a[deep][1],me);
	if(w2+1<=n/2)me=max(dfs(deep+1,w1,w2+1,w3)+a[deep][2],me);
	if(w3+1<=n/2)me=max(dfs(deep+1,w1,w2,w3+1)+a[deep][3],me);
	return dp[deep][w1][w2][w3]=me;
}

//int zhankai(){
//	for(int i=0;i<=n/2+5;i++)for(int j=0;j<=n/2+5;j++)for(int k=0;k<=n/2+5;k++){
//		dp[n+1][i][j][k]=0;
//		dp[0][i][j][k]=0;
//	}
//}
void solve0(){
	cout<<dfs(1,0,0,0)<<endl;
}
bool cmp(vector<int> fu1,vector<int> fu2){
	return fu1[1]>fu2[1];
}
void solve1(){
	sort(a.begin()+1,a.begin()+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[i][1];
	cout<<ans<<endl;
	a.clear();
}
long long solve2(int deep,int w1,int w2){
	if(deep>n)return 0;
	if(dpp[deep][w1][w2]!=-1)return dpp[deep][w1][w2];
	long long me=solve2(deep+1,w1,w2);
	if(w1+1<=n/2)me=max(solve2(deep+1,w1+1,w2)+a[deep][1],me);
	if(w2+1<=n/2)me=max(solve2(deep+1,w1,w2+1)+a[deep][2],me);
	return dpp[deep][w1][w2]=me;	
}
signed input() {
	bool A=true,B=true;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	a.resize(n+5);
	for(auto& i:a)i.resize(5,0);
	for(int i=1; i<=n; i++) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][3]!=0)B=false;
		if(a[i][3]!=0||a[i][2]!=0)A=false;
	}
	if(A)return 1;
	if(B)return 2;
	return 0;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		switch(input()){
			case 1:{
				solve1();
				break;
			}
			case 2:{
				dpp.resize(n+5);
				for(auto& i:dpp){
					i.resize(n/2+5);
					for(auto& j:i){
						j.resize(n/2+5,-1);
					}
				}
				cout<<solve2(1,0,0)<<endl;
				break;
			}
			default:{
				cout<<dfs(1,0,0,0)<<endl;
				break;
			}
		}
	}
	return 0;
}
