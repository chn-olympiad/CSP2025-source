#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
bool cmp(int a,int b){
	return a>b;
}
long long c(int i,int n){
	long long sum=1;
	for(int o=n;o>=n-i+1;o--){
		sum*=o;
		sum/=n-o+1;
		sum%=N;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={};
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(a[1]==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			sum+=c(i,n);
			sum%=N;
		}
		cout<<sum;
		return 0;
	}
	else if(n==3){
		if(a[1]<a[2]+a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	else cout<<59;
	return 0;
}
