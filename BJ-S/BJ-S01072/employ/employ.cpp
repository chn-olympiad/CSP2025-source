#include<bits/stdc++.h>
using namespace std;

const int MAXN = 503 , MOD = 998244353 ;

int n,m,res,tot,cc,s[MAXN],c[MAXN],c0;
bool use[MAXN];

void dfs(int d){
	if(d>n){
cerr<<tot<<"\n";
		res+=(tot>=m);
		if(res==MOD)
			res-=MOD;
	}else if(!s[d]){
		cc++;
		dfs(d+1);
	}else{
		for(int i=1;i<=n;i++){
			if(!use[i]){
				use[i]=true;
				if(cc>=c[i]) cc++;
				else tot++;
				dfs(d+1);
				use[i]=false;
				if(cc>=c[i]) cc--;
				else tot--;
			}
		}
	}
}

int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
		c0+=(!s[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	for(int i=1;i<=c0;i++){
		res=(long long)res*(n-i+1)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
// GOLD please