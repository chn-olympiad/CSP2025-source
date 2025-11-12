#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
char s[10005];
int n,m,ans,a[100005],mi=1,vis[100005];
void dfs(int w,int cnt,int fa){
	if(w>n){
		if(cnt>=m){
			ans++;
			ans%=998244353;
		//	cout<<ss<<" "<<fa<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			
			if(fa>=a[i] or s[w]=='0'){
				dfs(w+1,cnt,fa+1);
			}else{
				dfs(w+1,cnt+1,fa);
			}
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		mi=min(s[i]-'0',mi);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(mi==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}else if(m==n){
		cout<<0;
	}else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
