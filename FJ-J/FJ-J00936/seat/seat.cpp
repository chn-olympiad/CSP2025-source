#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],dp[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1);
	int len=n*m;
	for(int i=1;i<=n*m;i++){
		b[len]=a[i];
		len--;
	}
	int dx=1,dy=1;
	bool sx=0;
	for(int i=1;i<=n*m;i++){
		if(dy==n&&sx==0){
			dp[dy][dx]=b[i];
			dx+=1;
			sx=1;
		}
		else if(dy==1&&sx==1){
			dp[dy][dx]=b[i];
			dx+=1;
			sx=0;
		}
		else if(sx==0){
			dp[dy][dx]=b[i];
			dy+=1;
		}
		else{
			dp[dy][dx]=b[i];
			dy-=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==sum){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
