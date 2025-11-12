#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[10000001],sum,ans;
string s; 
bool vis[505];
void dfs(int f,int dep){
	if(dep==n){
		if(f>=m){
			ans++;
			ans=ans%mod;
	    }
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(a[i]>=dep-f-1&&s[dep]=='1')
				dfs(f+1,dep+1);
			else
				dfs(f,dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) if(s[i]=='1') sum++;
	if(sum<m) {
		cout<<0;
		return 0;
	} 
	int q=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) q=1;
	}
	if(q==0){
		int w=0,e=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1') {
				w++;
			}
			else{
				if(e==0) e=1;
				else break;
			}  
		}
		if(w<m){
			cout<<0;
			return 0;
		}
		int r=1;
		for(int i=1;i<=w;i++){
			r=r*i;
			r=r%mod;
		}
		cout<<e;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
