#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e4+10;
int a[N];
int n,k;
int dp[M][M];
int aaa[M][M];

int ans;
bool check(int x,int y){
	int sum;
	sum=a[x];
	for(int i=x+1;i<=y;i++)
		sum^=a[i];
	if(sum==k)return true;
	else return false;
}
void find_ans(int x){
	bool vis[N];
	memset(vis,0,sizeof vis);
	int sum=0;
	for(int i=x;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(dp[i][j]==1&&!vis[i]&&!vis[j]) {
				for(int k=i;k<=j;k++)vis[k]=1;
				sum++;
			}
		}	
	ans=max(ans,sum);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(check(i,j))dp[i][j]=1;
			

	for(int i=1;i<=n;i++){
		find_ans(i);
	}
	cout<<ans;
	return 0;
}

