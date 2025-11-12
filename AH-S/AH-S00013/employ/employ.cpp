#include<bits/stdc++.h>
using namespace std;
int pc[1001];
int p[1001];
int t[1001];
int ans;int n,m;
int h[1001];	string s;
bool v[1001];
void dfs(int d){
	if(d==n){
		int ggg=0,ss=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'&&ggg<h[i])ss++;else
			ggg++;
		}
		if(ss>=m){
			ans++;
		}
	}
	for(int i=0;i<n;i++){
		if(!v[i]){
			h[d]=p[i];
			v[i]=true;
			dfs(d+1);
			v[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	pc[0]=(s[0]=='0');
	for(int i=1;i<n;i++){
		pc[i]=pc[i-1];
		if(s[i]=='0'){
			pc[i]++;
		}
	}for(int i=0;i<n;i++){
		cin>>p[i];
		t[p[i]]++;
	}
	if(n<=18){
		
		dfs(0);
		cout<<ans;
		return 0;
	}
	if(pc[n-1]==0){
		if(n-t[0]>=m){
			int ans=1;
			for(int i=0;i<n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(pc[n-1]>n-m){
		cout<<0;
		return 0;
	}else if(m==n){
		long long ans=1;
		int g=0;
		for(int i=0;i<n;i++){
			int al=0;
			for(int j=0;j<n;j++){
				if(p[j]>pc[i]){
					al++;
				}
			}
			al-=g;
			ans*=al;
			g++;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
