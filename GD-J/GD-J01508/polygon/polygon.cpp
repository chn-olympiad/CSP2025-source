#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt,c;
int a[5005];
void dfs(int m,int sum,int s,int id,string st){
	if(s==n&&sum>m*2){
		ans=(ans+1)%998244353;
	}
	for(int i=id;i<=n;i++){
		string str=st;
		str+=i;
		dfs(max(m,a[i]),sum+a[i],s+1,i+1,str);
		dfs(m,sum,s+1,i+1,st);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
	}
	if(c==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		ans-=1;
		ans-=(n*(n+1)/2)%998244353;
		ans=(ans+998244353)%998244353;
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,1,"");
	cout<<ans;
	
	return 0;
}
