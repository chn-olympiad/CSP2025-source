#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[505],c[505],an=1,ans,x,k,v[505];
string s;
void dfs(int x,int as,int f){
	if(x==k+1){
		if(as>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
		return ;
	}
	f+=a[x];
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(c[i]>f) dfs(x+1,as+1,f);
			else dfs(x+1,as,f+1);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0')x++;
		else{
			a[++k]=x;
			x=0;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-k;i++) an=(an*i)%mod;
	dfs(1,0,0);
	cout<<(ans*an)%mod;
	return 0;
}/*
8+
*/
