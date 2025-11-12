#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550],c[550],ans=0;
bool tp=1;
string s;
long long jie(long long x){
	long long ans=1;
	for(int i=2;i<=x;i++)
		ans=ans*i%998244353;
	return ans;
}
void dfs(long long rs,long long k,long long lrs){
	if(k==n){
		if(lrs>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]) continue;
		c[i]=1;
		if(s[k]=='0'||rs>=a[i]) dfs(rs+1,k+1,lrs);
		else dfs(rs,k+1,lrs+1);
		c[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tp&&s[i]=='0') tp=false; 
	}
	if(tp){
		cout<<jie(n);
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}//Ô¤ÆÚµÃ·Ö 8+20(tepan) O(n!) 
