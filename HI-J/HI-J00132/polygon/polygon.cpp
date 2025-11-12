#include<bits/stdc++.h> 
using namespace std;
int n,a[5005],b[5005];
long long ans=0,sum=0;
void dfs(int k,int m,int j,int max){
	if(k==m+1){
		if(sum>2*max){
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	for(int i=j;i<=n;i++){
		if(k==1)max=a[i];
		sum+=a[i];
		dfs(k+1,m,i+1,max);
		sum-=a[i];
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==1){
		long long x=1;
		for(int i=0;i<n;i++)x=x*2%998244353;
		ans=x-n-n*(n-1)/2-1;
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++) {
		dfs(1,i,1,a[1]);
	}
	cout<<ans;
	return 0;
}
