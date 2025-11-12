#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],g=1,dp[10005],mx=0;
struct node{
	int x,y;
}b[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int s=a[i];
		if(s==m){
			b[g].x=i;
			b[g].y=i;
			g++;
			continue;
		}
		for(int j=i-1;j>=1;j--){
			s=s^a[j];
			if(s==m){
				b[g].x=j;
				b[g].y=i;
				g++;
				break;
			}
		}
	} 
	//正式dp
	dp[1]=1;
	for(int i=2;i<g;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(b[j].y<b[i].x)dp[i]=max(dp[i],dp[j]+1);
		}
		mx=max(mx,dp[i]);
	} 
	cout<<mx;
	return 0;
}