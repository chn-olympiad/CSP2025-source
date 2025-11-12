#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5,mod=998244353;
long long a[N],b[N];
long long pre[N],dp[5005][5005],vis[N];
long long n,m,k,t,sum=0,ans=0,mx=0,mn;
struct al{
	long long x,y,sum;
}c[N];
vector<long long>v;
string s,s1,s2;
map<pair<int,pair<string,int>>,long long>mp;
map<pair<int,pair<int,pair<string,int>>>,long long>mmp;
void dfs(int x,int y,string cnt,int mx){
	if(mmp[{x,{y,{cnt,mx}}}]>0)return ;
	mmp[{x,{y,{cnt,mx}}}]++;
	if(x>=n&&cnt.size()>=3&&y>mx*2){
//		
		mp[{y,{cnt,mx}}]++;
		if(mp[{y,{cnt,mx}}]==1){
			ans++;
//			cout<<y<<" "<<cnt<<" "<<mx<<endl;
			ans%=mod;
		}
		return ;
	}
	string s=cnt;	
	for(int i=x+1;i<=n;i++){
	
		dfs(i,y,cnt,mx);
		cnt+=to_string(i);
		dfs(i,y+a[i],cnt,a[i]);
		cnt=s;
//		mp[{y+a[i],{cnt+1,a[i]}}]++;
		
//		mp[{y+a[i],{cnt+1,a[i]}}]--;
//		mp[{y,{cnt,mx}}]++;
		
//		mp[{y,{cnt,mx}}]--;
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0); 
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,"",0);//位 和 个数 
	/*
	dp[1][0]=1;
//	dp[2][0]=1;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			dp[i]=dp[i-1][j];
			if(a[i])dp[i][j]=max(dp[i-1][j]*2,dp[i][j])%mod;
			mx=max(mx,dp[i][j]);
		}
	}
	cout<<mx;*/
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5

9

--
5
2 2 3 8 10

6
--

*/