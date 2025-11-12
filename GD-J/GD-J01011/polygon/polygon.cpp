#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5002],sum[5002];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n<3){
		cout<<"0";
	}else if(n==3){
		int nmax=max(a[1],max(a[2],a[3]));
		if(sum[n]>2*nmax){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
} 
