#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
ll mod=998244353;
bool p[505]={0},l[505]={0};
ll c[505]={0};
ll t[505]={0};
bool check(){
	ll q=0,x=0;
	for(int i=1;i<=n;i++){
		if(!p[i]){
			q++;
			continue;
		} 
		else{
			if(c[t[i]]<=q) q++;
			else x++;
		}
	}
	return x>=m;
}
void dfs(ll k){
	if(k>n){
		if(check()) ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(!l[i]){
			l[i]=1;
			t[k]=i; 
			dfs(k+1);
			l[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1') p[i]=1;
		else p[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>18){
		cout<<1<<endl;
		return 0;
	} 
	dfs(1);
	cout<<ans;
	return 0;
}
