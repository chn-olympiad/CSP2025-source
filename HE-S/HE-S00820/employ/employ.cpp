#include <bits/stdc++.h>
using namespace std;
const int N=507,mod=998244353;
int n,m;
bool s[N],flag=true,flag1=1,flag2=1;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		s[i]=a-'0';
		if(s[i]!=0) flag=false;
		if(s[i]!=1) flag2=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) flag1=0;
	}
	if(n==1&&m==1){
		if(c[1]==0||s[1]==0) cout<<0<<"\n";
		else cout<<1<<"\n";
		return 0;
	}
	if(flag){
		cout<<0<<"\n";
		return 0;
	}
	if(flag1){
		cout<<0<<"\n";
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]==0){
				cout<<"0\n";
				return 0;
			}
		}
		int ans=1; 
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans<<"\n";
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1) sum++;
	}
	if(sum<m){
		cout<<"0\n";
		return 0;
	}
	if(m==1){
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0) cnt++;
		}
		if(n-cnt==0){
			cout<<"0\n";
			return 0;
		}
		int taotai=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=taotai) taotai++;
			else ans=(ans+1)%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(flag2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0) cnt++;
		}
		if(n-cnt<m){
			cout<<"0\n";
			return 0;
		}
		int ans=1;
		for(int i=1;i<=m;i++) ans=(ans*(cnt-i+1))%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
