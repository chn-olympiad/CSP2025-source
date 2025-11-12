#include <bits/stdc++.h>
using namespace std;
long long n,t,arr[500000][3],dp[500000][3],m[3][3],mx1,mx2,mx3,mi1,mi2,mi3,a,o[3][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		m[0][0]=m[0][1]=m[0][2]=m[1][0]=m[1][1]=m[1][2]=m[2][0]=m[2][1]=m[2][2]=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>arr[j][0]>>arr[j][1]>>arr[j][2];
		}
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[0][1];
		dp[0][2]=arr[0][2];
		mx1=mx2=mx3=0;
		for(int j=0;j<3;j++){
			if(dp[0][j]>mx1){
				mx3=mx2;
				mx2=mx1;
				mx1=dp[0][j];
				mi3=mi2;
				mi2=mi1;
				mi1=j;
			}else if(dp[0][i]>mx2){
				mx3=mx2;
				mx2=dp[0][j];
				mi3=mi2;
				mi2=j;
			}else{
				mx3=dp[0][j];
				mi3=j;
			}
		}
		m[0][mi1]++;
		m[1][mi2]++;
		m[2][mi3]++;
		for(int j=1;j<n;j++){
			for(int k=0;k<3;k++){
				if(m[mi1][k]<n/2){
					dp[j][k]=arr[j][k]+mx1;
					o[k][0]=m[mi1][0];
					o[k][1]=m[mi1][1];
					o[k][2]=m[mi1][2];
					o[k][k]++;
				}
				else{
					dp[j][k]=arr[j][k]+mx2;
					o[k][0]=m[mi2][0];
					o[k][1]=m[mi2][1];
					o[k][2]=m[mi2][2];
					o[k][k]++;
				}
			}
			for(int ta=0;ta<3;ta++){
				for(int tb=0;tb<3;tb++){
					m[ta][tb]=o[ta][tb];
				}
			}
			mx1=mx2=mx3=0;
			for(int k=0;k<3;k++){
				if(dp[j][k]>mx1){
					mx3=mx2;
					mx2=mx1;
					mx1=dp[j][k];
					mi3=mi2;
					mi2=mi1;
					mi1=k;
				}else if(dp[j][k]>mx2){
					mx3=mx2;
					mx2=dp[j][k];
					mi3=mi2;
					mi2=k;
				}else{
					mx3=dp[j][k];
					mi3=k;
				}
			}
		}
		cout<<mx1<<endl;
	}
	return 0;
}
