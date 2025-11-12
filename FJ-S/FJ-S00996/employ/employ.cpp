#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,l,t[505],v[505],sum[505],ans,a[505];
long long one;
string s;
bool cmp(int x,int y){
	return x>y;
}
bool c(){
	int c=0,num=0;
	for(int i=1;i<=n;i++){
		if(c<sum[i]&&t[i]){
			num++;
		}else{
			c++;
		}
	}
	if(num>=m){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int k){
	if(k>n){
		if(c()){
			ans++;
			ans%=mod;	
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			sum[k]=a[i];
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		t[i+1]=s[i]-'0';
		if(t[i+1]==1){
			one++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(one<m){
		cout<<0;
		return 0;
	}else if(one==n){
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				c++;
			}
		}
		if(n-c>=m){
			ans=1;
			sort(a+1,a+n+1,cmp);
			
			for(int i=2;i<=c;i++){
				ans*=i;
				ans%=mod;
			}
			for(int i=2;i<=n-c;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
		}else{
			cout<<0;
			return 0;
		}
	}else if(n==m&&one<n){
		cout<<0;
		return 0;
	}else{
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				c++;
			}
		}
		if(n-c<m){
			cout<<0;
			return 0;
		}else{
			dfs(1);
			cout<<ans;
		}
	}
	return 0;
}
