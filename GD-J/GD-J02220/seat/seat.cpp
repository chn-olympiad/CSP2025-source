#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],dp[105][105],idx,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;int nm=n*m;
	for(int i=1;i<=nm;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+nm+1,cmp);
	if(m%2==0){
		for(int i=1;i<=m;i+=2){
			for(int j=1;j<=n;j++)dp[j][i]=a[++idx];
			for(int j=n;j>=1;j--)dp[j][i+1]=a[++idx];
		}
	}
	else{
		
		for(int i=1;i<=m-1;i+=2){
			for(int j=1;j<=n;j++)dp[j][i]=a[++idx];
			for(int j=n;j>=1;j--)dp[j][i+1]=a[++idx];
		}
		for(int j=1;j<=n;j++)dp[j][m]=a[++idx];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==dp[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}
