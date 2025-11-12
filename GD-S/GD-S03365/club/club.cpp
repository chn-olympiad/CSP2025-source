#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,a[10005][5],ma=0,s1=0,s2=0,s3=0;
	cin>>t;//s1为社团一的人数，s2为社团二的人数，s3为社团三的人数 
	bool b[100005];//是否已经被选中 
	long long cnt=0,dp[100005];
	dp[0]=0;
	for(long long i=1;i<=t;i++){
		cin>>n;
		cnt=0;
		long long n2=n/2;
		for(long long j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			
		}
		for(long long j=1;j<=n;j++){
			b[j]=1;
		}
//		for(long long j=1;j<=n;j++){
//			int s=max(a[k][1],a[k][2],a[k][3]);
//			dp[j]=dp[j-1]+s;
//		}
		for(long long j=1;j<=n2;j++){
			ma=0;
			long long xia=0;//最大值是谁 
			for(long long k=1;k<=n;k++){
				if(a[k][1]>ma&&b[k]==1){
					if(a[k][2]>a[k][1]&&a[k][2]>ma&&ma!=0){
						continue;
					}
					ma=a[k][1];
					xia=k; 
				}	
			}
			cnt+=ma;
			b[xia]=0;
//			cout<<ma<<" ";
		} 
		for(long long j=1;j<=n2;j++){
			ma=0;
			long long xia=0;//最大值是谁 
			for(long long k=1;k<=n;k++){
				if(a[k][2]>ma&&b[k]==1){
					ma=a[k][2];
					xia=k; 
				}	
			}
			cnt+=ma;
			b[xia]=0;
//			cout<<ma<<" ";
		}
		cout<<cnt<<endl; 
	}
	return 0;
} 
