#include<bits/stdc++.h>
#define N 100001
using namespace std;
int t,n,vis[N];
long long ans,dp[N][4];
struct node{
	int d[4];
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,memset(dp,0,sizeof(dp));int flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[2]!=0||a[i].d[3]!=0)flag=1;
		}
		if(flag==0){
			long long x;sort(a+1,a+n+1);
			for(int i=n/2;i<=n;i++)x+=a[i];
			cout<<x<<endl;
			return 0;
		}
		for(int k=1;k<=n;k++){
			for(int j=n/2;j>=1;j--){
				for(int i=1;i<=3;i++){
					dp[j][i]=max(dp[j][i],dp[j-1][i]+a[k].d[i]);
				}
			}
		}
		
		cout<<<<endl;
	}
	return 0;
}

