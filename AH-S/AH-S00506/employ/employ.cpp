#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[100010],cnt,vis[100010];
long long ans;
long long Ann(int a){
	long long res=1;
	for(int i=1;i<=a;i++){
		res=res*i%mod;
	}
	return res;
}
string s;
void dfs(int day,int get,int out){
	if(day>n){
		if(get>=m) ans=(ans+1)%mod;
		return ;
	}
	if(get==m){
		ans=(ans+Ann(n-day+1))%mod;
		return ;
	}
	if(n-out<m) return ;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[day]=='0'||out>=c[i]) dfs(day+1,get,out+1);
			else dfs(day+1,get+1,out);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
