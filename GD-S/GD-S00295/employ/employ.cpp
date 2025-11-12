#include <bits/stdc++.h>
using namespace std;
long long n,m,s=0,MOD=998244353,a[510];
string str;
bool v[510];
void dfs(long long x,long long sum,long long sum2){
	if(x==n){
		if(sum>=m){
			s=(s+1)%MOD;
		}
		return;
	}
	if(str[x]=='0'){
		for(int i=1;i<=n;i++){
			if(!v[i]){
				v[i]=1;
				dfs(x+1,sum,sum2+1);
				v[i]=0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!v[i]){
				if(a[i]>sum2){
					v[i]=1;
					dfs(x+1,sum+1,sum2);
					v[i]=0;
				}
				else{
					v[i]=1;
					dfs(x+1,sum,sum2+1);
					v[i]=0;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<s%MOD;
	return 0;
}
