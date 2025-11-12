#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,k;
const int N=5e5+5;
int a[N],id[N];
int dp[N];
int cnt;
int l,r;
int f[N];
int ans;
bool vis[N];
void init(int l,int r){
	for(int i=l;i<=r;i++){
		vis[i]=1;
	}
}
bool check(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i]==1)return 0;
	}
	return 1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=1;len<=n;len++){
		memset(vis,0,sizeof vis);
		memset(dp,0,sizeof dp);
		cnt=0;l=0,r=0;
		for(int i=len;i<=n;i++){
			if(!vis[i]){
				dp[i]=dp[i-1]^a[i];
				if(l==0)l=i;
				r=i;
				if((dp[i]==k||a[i]==k)&&check(l,r)){
					cnt++;
					init(l,r);
					l=r=0;
					dp[i]=0; 
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}//ÎÒÕ¦¸Ð¾õÏñDP
/*
4 2 
2 1 0 3 

2
*/
/*
4 3 
2 1 0 3 
b
2 
*/
/*
4 0 
2 1 0 3 

1
*/
