#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=510;
int n,m,a[N],c[N],ans=0,b[N],o[15];
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cnt++;
			}else if(cnt>=c[b[i]]){
				cnt++;
			}
		}
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		if(!o[i]){
			o[i]=1;
			b[x]=i; 
			dfs(x+1);
			o[i]=0;
		}
	}
}
void Sub1(){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	} 
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool sub1=1;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
		if(!a[i])sub1=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(sub1){
		Sub1();
	}else if(m==n){
		if(!sub1)cout<<"0";
		else{
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					cout<<"0";
					return 0;
				}
			}
			Sub1();
		}
	}else if(n<=10){
		dfs(1);
		cout<<ans;
	}
	return 0;
}

