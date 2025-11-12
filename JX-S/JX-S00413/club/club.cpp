#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e3+2;
int T,n,n1;
int p[4];
struct em{
	int part,w; 
	bool vis=false; 
};
em res[N];
vector<vector<em> > dp(N,vector<em>(4));
bool cmp(em a,em b){
	return a.w>b.w;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>n;
		n1=n>>1; 
		p[1]=p[2]=p[3]=0;
		for(int i=1;i<=n;i++){
			cin>>dp[i][1].w>>dp[i][2].w>>dp[i][3].w;
			dp[i][1].part=1;
			dp[i][2].part=2;
			dp[i][3].part=3;
			res[i].w=0;
		}
		// cout<<endl;
		for(int i=1;i<=n;i++){
			sort(dp[i].begin()+1,dp[i].end(),cmp); 
		}  
		if(n1==1){
			cout<<max(dp[1][1].w+dp[2][2].w,dp[1][2].w+dp[2][1].w)<<endl;
		} 
	}
	return 0;
}