#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],b[510],a[510],e[510],ss;
string s;
void dfs(int d) {
	if(d==n+1) {
		int ans=0,f=0;
		for(int i=1;i<=n;i++) {
			if(c[a[i]]<=f||s[i-1]=='0') f++; 
			else ans++;
		}
		if(ans>=m) ss=(ss+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!b[i]) {
			b[i]=1;
			a[d]=i;
			dfs(d+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d",ss);
	
	return 0;
} 
