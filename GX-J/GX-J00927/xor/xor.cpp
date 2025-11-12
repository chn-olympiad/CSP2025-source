#include<bits/stdc++.h>
using namespace std;
struct qujian{
	int x,y;
}a[500001];
int n,k,t=1;
bool check(int l,int r){
	for(int i=1;i<t;i++)
		if((a[i].x>=l&&a[i].x<=r)||(a[i].y>=l&&a[i].y<=r))return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int dp[n+1][n+1];
	for(int i=1;i<=n;i++)
		cin>>dp[i][i];
	for(int len=2;len<=n;len++){
		int l=1,r=len;
		while(r<=n){
			dp[l][r]=dp[l][r-1]^dp[r][r];
			l++;r++;
		}
	}
	for(int len=1;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
			if(dp[i][i+len-1]==k&&check(i,i+len-1)){
				a[t]={i,i+len-1};
				t++;
			}
	cout<<t-1<<endl;
	return 0;
}
