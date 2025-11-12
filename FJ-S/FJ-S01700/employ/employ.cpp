#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],p[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>c[i],p[i]=i;
	int cnt=0;
	for(int i=0;i<n;++i){
		if(s[i]=='1')++cnt;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
/*	if(m==1){
		int mx=0,id=0;
		for(int i=1;i<=n;++i)mx=max(mx,c[i]);
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				id=i;
				break;
			}
		}
		if(id)
	}*/
	/*
	if(m==1){
		long long ans=0;
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				for(int j=1;j<=n;++j){
					if(c[j]>i)++ans;
				}
			}
		}
		for(int i=1;i<n;++i)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}*/
	if(cnt==n&&m==n){
		for(int i=1;i<=n;++i){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=2;i<=n;++i)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	int ans=0;
	do{
		int f=0;
		for(int i=1;i<=n;++i){
			if(f>=c[p[i]]){
				++f;
			}else{
				if(s[i-1]=='0')++f;
			}
			if(i-f>=m){
				ans=(ans+1)%mod;
				break;
			}
		}
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;	//8pts
	
	return 0;
} 
