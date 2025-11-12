#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int f[505];
long long ans=0;
void dfs(int id){
	if(id==n+1){
		int t=0,l=0;
		for(int i=1;i<=n;i++){
			if(t>=c[f[i]]){
				t++;	
			}else if(s[i]=='0'){
				t++;
			}else{
				l++;
			}
		}
		if(l>=m){
			ans++;
		}
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=id;
			dfs(id+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s=' '+s;
	dfs(1);
	cout<<ans%99824435;
	return 0;
}