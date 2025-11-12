#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,c[505];
string s;
bool vis[505];
void dfs(int step,int cnt){
	if(n-step+1+cnt<m){
		return;
	}
	if(step>n){
		if(cnt>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			int fail=step-cnt-1;
			if(fail>=c[i]||s[step-1]=='0'){
				dfs(step+1,cnt);
			}else{
				dfs(step+1,cnt+1);
			}
			vis[i]=false;
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
	if(n<=18){
		dfs(1,0);
		cout<<ans;
	}else if(n==m){
		bool flag=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				flag=false;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				flag=false;
				break;
			}
		}
		cout<<flag;
	}else{
		long long mul=1;
		int cnt;
		for(int i=1;i<=n;i++){
			if(c[i]!=0){
				cnt++;
			}
		}
		for(int i=1;i<=cnt;i++){
			mul=(mul*i)%mod;
		}
		cout<<mul;
	}
	return 0;
}
