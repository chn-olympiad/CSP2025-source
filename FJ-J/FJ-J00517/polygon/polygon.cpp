#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=5005;
int n,ans;
int num[max_n],is;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(num[i]!=1){
			is=1;
		}
	}
	if(n<3){
		cout << 0;
		return 0;
	}
	if(n==3){
		if(max(max(num[1],num[2]),num[3])*2<num[1]+num[2]+num[3] ){
			cout << 1;
			return 0;
		}
		cout << 0 ;
		return 0; 
	}
	if(is==0){
		int sum=0;
		for(int i=3;i<=n;i++){
			int sum1=1;
			int sum2=1;
			for(int j=n;j>=n-i+1;j--){
				sum1*=j;
			}
			for(int j=i;j>=1;j--){
				sum2*=j;
			}
			sum=(sum+sum1/sum2)%998244353;
		}
		cout << sum;
		return 0;
	}
	
	return 0;
} 
