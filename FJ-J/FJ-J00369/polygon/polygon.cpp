#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005],m,n,ans,mod=998244353;
void dfs(int sum,int maxx,int x,int y,int z){
	if(x+1==y){
		if(sum>maxx*2){
			ans++;
		}
		return;
	}
	for(int i=z;i<=n;i++){
		if(s[i]==0){
			s[i]=1;
			dfs(sum+a[i],max(maxx,a[i]),x,y+1,i);
			s[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)m=1;
	}
	if(m==0){
		for(int i=1;i<=n-2;i++){
			ans+=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=0,maxx=0;
		for(int i=1;i<=3;i++){
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(sum>maxx*2)cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(0,0,i,1,1);
	}
	cout<<ans;
	return 0;
}
