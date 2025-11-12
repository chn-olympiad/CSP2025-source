#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx;
int main( ){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*maxx){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	if(maxx==1){
		long long sum=0;
		for(int i=1;i<=n-2;i++){
			sum=sum+i*(n-i-1);
			sum%=998244353;
		}
		cout<<sum;
	}
	return 0;
}

