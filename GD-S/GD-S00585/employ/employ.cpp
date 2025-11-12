#include<bits/stdc++.h>
using namespace std;
int n,m,su,sum,ans=0,k1=0,k2=0,a[505],b[505],vis[505];
string s;
void dfs(int k){
	if(k>=n){
		su=0;
		sum=0;
		for(int i=0;i<n;i++){
			if(su>=a[b[i]]){
				su++;
				continue;
			}
			if(s[i]=='1'){
				sum++;
			}
			else{
				su++;
			}
		}
		if(sum>=m){
			ans=(ans+1)%998244353;
		}
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=18){
		dfs(0);
		cout<<ans<<endl;
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				k1=1;
			}
			if(a[i]>0){
				k2++;
			}
		}
		if(k1==0||k2==0){
			cout<<0<<endl;
		}
		else{
			ans=1;
			for(int i=2;i<n;i++){
				ans=(ans*i)%998244353;
			}
			ans=(ans*k2)%998244353;
			cout<<ans<<endl;	
		}
	}
	else if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				k1++;
			}
			if(a[i]==0){
				k2=1;
			}
		}
		if(k1==n&&k2!=1){
			ans=1;
			for(int i=2;i<=n;i++){
				ans=(ans*i)%998244353;
			}
			cout<<ans<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				k1++;
			}
			if(a[i]>0){
				k2++;
			}
		}
		if(k1<m||k2<m){
			cout<<0<<endl;
		}
		else if(k1==n){
			ans=1;
			for(int i=2;i<n;i++){
				ans=(ans*i)%998244353;
			}
			ans=(ans*k2)%998244353;
			cout<<ans<<endl;
		}
		else{
			dfs(0);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
