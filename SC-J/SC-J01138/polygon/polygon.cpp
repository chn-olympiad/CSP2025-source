#include<bits/stdc++.h>
using namespace std;
const long long m=998244353;
int n;
int a[5010];
long long ans[5010];
int maxm;
long long sum;
long long func(int i){
	long long t=((((i*(i-1))%m)*(i-2))%m)/6;
	return t%m;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxm=max(maxm,a[i]);
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>maxm*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=3;i<=n;i++){
			ans[i]=sum+func(i);
			ans[i]%=m;
			sum+=ans[i];
		}
		cout<<ans[n];
	}
	return 0;
}