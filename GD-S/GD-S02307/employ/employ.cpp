#include<bits/stdc++.h>
using namespace std;
int const mod=998244353;
int c[600],A[600];
int n,m;
bool vis[600];
string s;
long long ans;
int un_pass,pass;
bool pd;
void dfs(int dep){
	if(dep){
		if(!pd){
			if(s[dep-1]=='0'){
				un_pass++;
			}
			else{
				pass++;
			}
		}
		else un_pass++; 
	}
	pd=0;
	if(pass>=m){
//		cout<<endl;
//		cout<<n-dep<<' '<<pass<<endl<<endl;
		ans+=A[n-dep];
		ans%=mod;
		return;
	}
	if(dep>=n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(c[i]<=un_pass)pd=1;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
			if(c[i]>un_pass){
				if(s[dep]=='0')un_pass--;
				else pass--;
			}
			else un_pass--;
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
	long long res=1;
	A[0]=1;
	for(int i=1;i<=n;i++){
		res*=i;
		res%=mod;
		A[i]=res;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
