#include<bits/stdc++.h>
using namespace std;
int n;
int a[5018],dp[5018][5018];
const int MOD=998244353;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int j=3;j<=n;j++){
		for(int i=1;i<=n-j+1;i++){
			if(j==3){
				int sm=0,mx=0;
				for(int l=0;l<3;l++){
					sm+=a[i+l];
					mx=max(mx,a[i+l]);
				}
				if(sm>2*mx)dp[i][j]=1;
			}
			else{
				cout<<i<<" "<<j<<endl;
				dp[i][j]+=2*dp[i][j-1];
				for(int l=i;l<=i+j-2;l++){
					//cout<<l<<endl;
					for(int k=i+j-2;k>=l+1;k--){
						//cout<<k<<endl;
						//cout<<a[l]<<" "<<a[k]<<" "<<a[i+j-1]<<endl;
						if(a[l]-a[k]<a[i+j-1]){
							dp[i][j]+=k-l;
							//cout<<"gggg"<<endl;
							break;
						}
					}
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<dp[1][n];
	return 0;
}
