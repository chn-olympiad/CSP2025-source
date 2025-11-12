#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,a1=0,a2=0,a3=0;
	long sum=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin>>t>>n;
	for(long long l=0;l<t;l++){
		long long d[n][3];
//		for(long long j=0;j<n;j++){
//			for(long long r=0;r<3;r++){
//				cin>>d[j][r];
//			}
//		}
		for(long long i=0;i<n;i++){
			long long m=max(d[i][0],max(d[i][1],d[i][2]));
			sum+=m;
		}
		cout<<sum;
	}
	return 0;
}

