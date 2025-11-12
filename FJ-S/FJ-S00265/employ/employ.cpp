#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum_c,c[550],b[25],sum_m;
string s;
bool vis[550];
void dfs(int step){
	if(step==n+1 &&sum_m>m){
		ans++;
		ans%=998244353;
		return; 
	}
	
	for(int i=1;i<=n;i++){
		if(s[step-1]=='0' && vis[i]==false){
			sum_c++;
			b[step]=i;
			vis[i]=true;
			dfs(step+1);
			vis[i]=false;
			sum_c--;
		} 
		else if(sum_c<c[i] && vis[i]==false){
			b[step]=i;
			sum_m++;
			vis[i]=true;
			dfs(step+1);
			vis[i]=false;
		}
		else if(sum_c>c[i]){
			sum_c++;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1); 
	cout<<ans%998244353;
	return 0;
}
