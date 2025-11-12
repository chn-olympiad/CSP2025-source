#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+10;
int n,a[N],cnt;
int c(int n,int m){
	if(n/2<m)return c(n,n-m);
	int q=1;
	for(int i=1;i<=m;i++){
		q*=(n-i+1)/i;
	}
	return q%998244353;
}
void dfs(int Id,int m,int sum){
	if(sum>2*m)cnt++;
	if(Id==n)return;
	for(int i=Id+1;i<=n;i++){
		dfs(i,max(m,a[i]),sum+a[i]);
	}
	return;
}
void solve(){
	cin>>n;
	bool b=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])b=1;
	}
	if(b){dfs(0,0,0);cout<<cnt;
	}
	else {
		for(int i=3;i<=n;i++){
			cnt+=c(n,i); 
			cnt%998244353;
		}
		cout<<cnt;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int _=1;//cin>>_;
	while(_--)solve();
}
