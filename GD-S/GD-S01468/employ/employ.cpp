#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,mod=998244353;
ll n,m,s[N],c[N],tt,a[N],b[N],tot,tt,w[N],o[N],ans;
string s1;
void dfs(int x){
	if(x==n+1){
		int tt=0,op=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=op||s[i]==0)op++;
			else tt++;
		}
		tot+=(tt>=m);
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1,a[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s1;
	for(int i=1;i<=n;i++)s[i]=s1[i-1]-'0',tt+=s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]==0)return cout<<"0",0;
		}
		ll as=1;
		for(int i=1;i<=n;i++)as=as*i%mod;
		cout<<as;
		return 0;
	}
	if(tt<m)return cout<<"0",0;
	dfs(1);
	cout<<tot;
	return 0;
}
