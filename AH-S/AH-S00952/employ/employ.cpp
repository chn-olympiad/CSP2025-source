#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[510],d[510],v[510];
long long sum,P=998244353;
bool vis[510];
string s;
int t=0;
void dfs(int q,int s){
	if(q>n-m)return ;
	if(s==n+1){
		if(n-q>=m){
			sum=(sum+1)%998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(d[s]==0){
				vis[i]=1;
				dfs(q+1,s+1);
				vis[i]=0;
			}
			else{
				if(q>=a[i]){
					vis[i]=1;
					dfs(q+1,s+1);
					vis[i]=0;
				}
				else {
					vis[i]=1;
					dfs(q,s+1);
					vis[i]=0;
				}
			}
		}
	}
	return ;
}
void f(int q,int s,int c){
	if(q>n-m)return ;
	if(s==n+1){
		if(n-q>=m){
			sum=(sum+1)%998244353;
		}
		return ;
	}
	if(c==1){
		sum=(sum+v[n-s+1])%P;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(d[s]==0){
				vis[i]=1;
				f(q+1,s+1,c);
				vis[i]=0;
			}
			else{
				if(q>=a[i]){
					vis[i]=1;
					f(q+1,s+1,c);
					vis[i]=0;
				}
				else {
					vis[i]=1;
					f(q,s+1,c+1);
					vis[i]=0;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		d[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v[0]=1;
	for(int i=1;i<=500;i++){
		v[i]=v[i-1]*i%P;
	}
	if(m==1){
		f(0,1,0);
		cout<<sum;
		return 0;
	}
	dfs(0,1);
	cout<<sum;
	return 0;
}
