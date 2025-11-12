#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[505],c[505],t,s,mod=998244353,y,u;
bool p[505],f[505];
char x;
void aa(ll k){
	if(k>n){
		t=0;y=0;
		for(int i=1;i<=n;i++){
			if(y>=c[i]||!p[i])y++;
			else t++;
		}
		if(t>=m)s=(s+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			c[k]=a[i];
			f[i]=1;
			aa(k+1);
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='1'){
			p[i]=1;
			u++;
		}
	}
	if(m>u){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)u--;
	}
	if(u==n){
		s=1;
		for(ll i=1;i<=n;i++)s=(s*i)%mod;
		cout<<s;
		return 0;
	}
	aa(1);
	cout<<s;
	return 0;
} 
