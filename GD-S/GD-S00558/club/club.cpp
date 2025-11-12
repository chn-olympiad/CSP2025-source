#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3;

int max(int a,int b,int c){
	return max(max(a,b),c);
}
int min(int a,int b,int c){
	return min(min(a,b),c);
}
int mi(int a,int b,int c){
	return a+b+c-max(a,b,c)-min(a,b,c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	vector<vector<int>> a(N,vector<int>(4));
	vector<ll> dp(N);
	vector<int> cnt(4);
	
	while(_--){
		
		vector<priority_queue<int,vector<int>,greater<int>>> q(4);
		cnt[1]=cnt[2]=cnt[3]=0;
		int n;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			int mx=1;
			if(a[i][2]>a[i][mx]) mx=2;
			if(a[i][3]>a[i][mx]) mx=3;
		}
		dp[1]=max(a[1][1],a[1][2],a[1][3]);
		int mx=0;
		for(int i=1;i<=n;i++){
			int mid=mi(a[i][1],a[i][2],a[i][3]),mxx=max(a[i][1],a[i][2],a[i][3]);
			mx=1;
			if(a[i][2]>a[i][mx]) mx=2;
			if(a[i][3]>a[i][mx]) mx=3;
			dp[i]=0;
			if(cnt[mx]<n/2){
				dp[i]=dp[i-1]+a[i][mx];
				cnt[mx]++;
				ll x=mxx-mid;   
				q[mx].push(x);
				
			} 
			else{
				dp[i]=dp[i-1]+a[i][mx]-q[mx].top(); //替代代价最小的 ，自己过去（） 
				if(dp[i]>=dp[i-1]+mid){
					q[mx].pop();
					ll x=mxx-mid; //替换的代价（越小越好）
					q[mx].push(x);
				}else{
					dp[i]=dp[i-1]+mid;     
				}
				
			}
		}
		cout<<dp[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
