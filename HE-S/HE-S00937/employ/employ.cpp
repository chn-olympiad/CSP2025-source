#include<bits/stdc++.h>
using namespace std;
int n,m,f,sumc;
string s;
int c[505];
int p[505];
int vis[505];
long long ans;
long long cheng(int x){
	long long res=1;
	for(int i=x;i>=1;i--){
		res=1ll*(res%998244353)*(i%998244353)%998244353;
	}
	return res;
}
bool check(){
	int cc=0,lu=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'&&c[p[i]]>cc)lu++;
		else cc++;
	}
	if(lu>=m)return true;
	else return false;
}
long long dfs(int x){
	if(x>n){
//		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//		cout<<endl;
		if(check()){
			ans++;
			ans=ans%998244353;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				p[x]=i;
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)sumc++;
	}
	for(int i=1;i<s.size();i++){
		if(s[i]=='0')f=1;
	}
	if(n-sumc<m){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans%998244353;
	
	return 0;
} 
