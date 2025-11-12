#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=500+6,M=2e6+6,P=998244353;
int n,m;string s;
int c[N];int ans=0;int vis[N];int num[N];
void dfs(int x){
	if(x>n){
		int now=0,ta=0;
		f(i,1,n){
			if(c[num[i]]<=ta){ta++;continue;} 
			if(s[i]=='1'){
				now++;
			}else{
				ta++;
			}
		}
		if(now>=m)ans++;
		return ;
	}f(i,1,n){
		if(vis[i]==0){
			vis[i]=1;num[x]=i;
			dfs(x+1);vis[i]=0;
		} 
	} 
	
}
int dp[N][N];
int po(int x,int y){
	int ans=1;f(i,1,y)ans*=x;
	return ans;
}int cnt[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;f(i,1,n)cin>>c[i];
	sort(c+1,c+1+n);
	f(i,1,n)cnt[c[i]]++; 
	if(m==1){
		int num=po(2,n);
		dp[0][0]=1;
		f(i,0,s.size()-1){
			f(j,1,n){
				dp[i][j]+=dp[i-1][j-cnt[i-1]];
				if(s[i]=='1'){
					dp[i][j]=dp[i-1][j+1]*(j+1)%P;
					dp[i][j]%=P;
				}else{
					dp[i][j]=dp[i-1][j+1]*(j+1)%P+dp[i-1][j]*((n-i+1)-j)%P;
					dp[i][j]%=P;
				}	
			} 
		} 
		cout<<(num-dp[n][0]+P)%P;
		return 0;
	}
	dfs(1);cout<<ans;
} 
/*
6 6 1
1 3 6
1 5 1
1 2 3
2 6 6
5 6 4
3 5 2
0 1 1 1 1 1 1
*/