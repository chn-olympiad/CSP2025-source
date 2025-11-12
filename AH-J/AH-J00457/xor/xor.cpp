#include"bits/stdc++.h"
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,k;
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[N];
	}
	if(k==0){
		int cnt=0,n=m;
		for(int i=2;i<=n;i+=2){
			int sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum*=j;
			}
			int sum2=sum;
			for(int j=i;j>=1;j--){
				sum2/=j;
			}
			cnt+=sum2;
		}
		cout<<cnt;
	}
	return 0;
}
