#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],sum,ans,co;
string s;
bool book[505];
void dfs(int k,int gu){
	if(k>n){
		if(n-gu>=m)sum=(sum+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			if(gu>=c[i]||s[k-1]=='0'){
				dfs(k+1,gu+1);
			}else dfs(k+1,gu);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)co++;
	}
	for(int i=0;i<n;i++)ans+=s[i]-'0';
	if(ans<m||n-co<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<sum;
	return 0;
}
