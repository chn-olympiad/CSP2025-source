#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long N=998244353; 
long long ans=0;
void dfs(int step,int mark,int num,int n){
	if(step>=2&&num+a[n]>a[n]*2){
		ans++;
		ans%=N;
	}
	for(int i=mark+1;i<n;i++){
		dfs(step+1,i,num+a[i],n);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
		}
		else {
			cout<<"0";
		}
		return 0;
	}
	if(a[n]==1){
		long long num=0;
		long long sum1=n*(n-1)*(n-2);
		long long sum2=6;
		num+=sum1/sum2;
		for(int i=4;i<=n;i++){
			sum1*=(n-i+1);
			sum2*=i;
			num+=sum1/sum2;
			num%=N;
		}
		cout<<num%N;
	}
	for(int i=3;i<=n;i++){
		dfs(0,0,0,i);
	}
	cout<<ans%N;
	return 0;
}
