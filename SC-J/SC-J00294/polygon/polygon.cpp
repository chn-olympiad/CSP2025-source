#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=5000+6,P=998244353;int a[N];
int dp[3][N*2];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;cin>>n;f(i,1,n)cin>>a[i];
	sort(a+1,a+1+n,greater<>());
	int maxn=a[1]+1;
	f(i,1,n){
		int now,lst;if(i%2==1)now=1,lst=0;else now=0,lst=1;
		f(j,0,maxn)dp[now][j]=0; 
		dp[now][a[i]+1]=1;
		f(j,0,maxn){
			if(j-a[i]>=0)dp[now][j-a[i]]+=dp[lst][j],dp[now][j-a[i]]%=P;
			else dp[now][0]+=dp[lst][j],dp[now][0]%=P;
		}
		f(j,0,maxn){dp[now][j]+=dp[lst][j];dp[now][j]%=P;}
	}
	cout<<dp[n%2][0]%P;
}