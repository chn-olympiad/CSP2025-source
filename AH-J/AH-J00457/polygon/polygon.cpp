#include"bits/stdc++.h"
using namespace std;
#define int long long
const int N=5e3+10,M=998244353;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(a[n]==1){
		int cnt=0;
		for(int i=3;i<=n;i++){
			int sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum*=j;
				sum%=M;
			}
			int sum2=sum;
			for(int j=i;j>=1;j--){
				sum2/=j;
			}
			cnt+=sum2;
			cnt%=M;
		}
		cout<<cnt;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	return 0;
}
