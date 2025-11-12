#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k,sum=1,dp[N],ma,gt=1;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		int ma=max(a[i],a[i-1]);
//		int mi=min(a[i],a[i-1]);
//		b[i]=ma-mi;
//		
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		sum=0;
		if(a[i]==k){
			ma=max(ma,1);
			gt=0;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum=a[j]^sum;
			if(sum==k){
				gt=1;
				ma=max(ma,j-i);
				break;
			}
		}
	}
	cout<<ma+gt%2;
	return 0;
} 
