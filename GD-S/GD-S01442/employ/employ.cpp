#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[509];
int c[509];
int mod=998244353;
int ans,b[509];
//
void dfs(int x,int s,int t){
	if((n-x+1)+t<m)return;
	if(x>n){
		if(t>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=x;
			if(s>=c[i]||ch[x]=='0')dfs(x+1,s+1,t);
			else dfs(x+1,s,t+1);
			b[i]=0;
		}
	}
}
void run1(){
	dfs(1,0,0);
	cout<<ans;
}
void run2(){
	int bj=0;
	for(int i=1;i<=n;i++)if(ch[i]=='0')bj=1;
	for(int i=1;i<=n;i++)if(c[i]==0)bj=1;
	ans=1;
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	if(bj==1)cout<<0;
	else cout<<ans;
}
void run3(){
	int cnt=0;
	for(int i=1;i<=n;i++)if(c[i]==0)cnt++;
	if(n-cnt<m){
		cout<<0;
		return;
	}
	ans=1;
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sp=0;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
		if(ch[i]=='0')sp=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)run1();
	else if(n==m)run2();
	else if(sp==0)run3();
	return 0;
}
