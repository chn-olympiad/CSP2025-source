#include<bits/stdc++.h>
using namespace std;
int a[5000];
int ans;int n;
void dfs(int x,int f,int sum){
	if(f==1){
		for(int j=x+1;j<=n;j++){
			sum+=a[j];
			dfs(j,0,sum);
			sum-=a[j];
		}
	}else{
		for(int j=x+1;j<=n;j++){
			sum+=a[j];
			if(sum>a[j]*2)ans++;
			dfs(j,0,sum);
			sum-=a[j];
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag){
		cout<< (n*n-3*n+2)/2 ;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(a[n]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int f=1;
		int sum=a[i];
		dfs(i,f,sum);
	}
	cout<<ans;
	return 0;
}
