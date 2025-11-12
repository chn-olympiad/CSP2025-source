#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,ans=0;
bool cmp(int a,int b){
	return a>b;
}
int b(int x){
	int cnt=1;
	for(int i=1;i<=x;i++) cnt*=2;
	return cnt;
}
int dfs(int x,int i,int s){
	if(s>x) return b(n-i+1)%998244353;
	if(i>n) return 0;
	int d=0;
	for(int j=0;j<=1;j++){
		d+=dfs(x,i+1,s+a[i]*j);
		d%=998244353;
	}
	return d;
}
int main(){
	freopen("polygon.in","r",stdin);
	freoepn("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n-1;i++){
		sum-=a[i];
		if(a[i]<sum){
			ans+=dfs(a[i],i+1,0);
		}
	}
	cout<<ans;
	return 0;
}
