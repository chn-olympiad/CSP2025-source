#include<iostream>
#include<algorithm>
using namespace std;
int aa;
int n,m;
int dp[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>dp[i];
	aa=dp[1];
	sort(dp+1,dp+1+n*m);
	int r=0;
	for (int i=1;i<=n*m;i++)if (dp[i]==aa)r=i;
	r=n*m-r+1;
	int t=0;
	while(t*n<r){
		t++;
	}
	int x=t,y=r-t*n+n;
	if (t%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
