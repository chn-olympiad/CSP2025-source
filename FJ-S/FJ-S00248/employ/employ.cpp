#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gn 998244353
//rerecycyclcl
int n,m,c[505],lugan,vis[505],gg[505],ans;
bool da=1;
string s;
void dfs(int stp){
	if(stp>n){
		int fq=0,sum=0;
		for(int i=1;i<=n;i++){
			if(c[gg[i]]<=fq){
				fq++;
			}
			else if(s[i]=='1'){
				sum++;
			}
			else{
				fq++;
			}
		}
		if(sum>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			gg[stp]=i;
			dfs(stp+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int t=s.size();
	s=' '+s;
	for(int i=1;i<=t;i++){
		if(s[i]=='0')da=0;
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else if(da){
		
		return 0;
	}
	return 0;
}
