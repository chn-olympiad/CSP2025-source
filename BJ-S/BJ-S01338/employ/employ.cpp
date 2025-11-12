#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const long long mod=998244353;
string s;
int n,m,c[MAXN];
long long t[MAXN],dp[MAXN][MAXN][MAXN];
int vis[MAXN],ans;
void dfs(int id,int num,int cnt){
	if(id==n+1){
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(id+1,num+((c[i]<=num)|(s[id-1]=='0')),cnt+((c[i]>num)&(s[id-1]=='1')));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i],t[c[i]]++;
	if(n<=18){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}else if(m==n){
		bool flag=1;
		for(int i=1;i<=n;i++)flag&=(s[i-1]=='1');
		for(int i=1;i<=n;i++)flag&=(c[i]!=0);
		if(!flag)cout<<0;
		else{
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		return 0;
	}
	/*if(m==1){
		long long cnt=t[0];
		for(int i=1;i<n;i++){
			if(s[i-1]=='1'){
				for(int j=1;j<=n;j++){
				
				}
				dp[i][j][k]
			}
			for(int j=0;j<=cnt;j++){
			
			}
		}
		why string?
		qwq I hate string
		It's the third time I had get unpleasant score in the CSP-S
		I think I had to AFO after this contest.
		May be I can have a chance to get 1= and go to the NOIP?
		the final score is 100+100+25+12=237. 
		I hope I can get 1= qwq.
		one thing is good today is that I only use 30 to get all new 6 star in mrfz
		the reason why I have died today is that I cost 1 hours for T2.
		I had read the road3.ans when I was test road2.in   qwq
		I have realized that I need to have the mid-term test in 2025.11.14
		I still have to die on that day although I haven't die today.
		qwq
		I hate string.
		I hope that the 1= line will little than 200
	}*/
	return 0;
}